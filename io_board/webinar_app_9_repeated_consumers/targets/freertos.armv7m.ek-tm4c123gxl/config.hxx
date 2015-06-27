#include "nmranet/SimpleNodeInfo.hxx"
#include "nmranet/ConfigRepresentation.hxx"

#include "nmranet/MemoryConfig.hxx"
#include "nmranet/ConfiguredConsumer.hxx"

namespace nmranet
{

extern const SimpleNodeStaticValues SNIP_STATIC_DATA = {4, "OpenMRN",
    "Test IO Board - Tiva Launchpad 123", "ek-tm4c123gxl", "1.01"};

/// Declares a repeated group of a given base group and number of repeats.
typedef RepeatedGroup<ConsumerConfig, 3> AllConsumers;

/// Defines the main segment in the configuration CDI. This is laid out at
/// origin 128 to give space for the ACDI user data at the beginning.
CDI_GROUP(IoBoardSegment, Segment(MemoryConfigDefs::SPACE_CONFIG), Offset(128));
CDI_GROUP_ENTRY(consumers, AllConsumers, Name("Outputs"));
CDI_GROUP_END();

/// The main structure of the CDI. ConfigDef is the symbol we use in main.cxx
/// to refer to the configuration defined here.
CDI_GROUP(ConfigDef, MainCdi());
/// Adds the <identification> tag with the values from SNIP_STATIC_DATA above.
CDI_GROUP_ENTRY(ident, Identification);
/// Adds an <acdi> tag.
CDI_GROUP_ENTRY(acdi, Acdi);
/// Adds a segment for changing the values in the ACDI user-defined
/// space. UserInfoSegment is defined in the system header.
CDI_GROUP_ENTRY(userinfo, UserInfoSegment);
CDI_GROUP_ENTRY(seg, IoBoardSegment);
/// Closes the CDI declaration.
CDI_GROUP_END();

} // namespace nmranet
