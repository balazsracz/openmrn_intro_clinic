#include "nmranet/SimpleNodeInfo.hxx"
#include "nmranet/ConfigRepresentation.hxx"

#include "nmranet/MemoryConfig.hxx"
#include "nmranet/ConfiguredConsumer.hxx"

namespace nmranet
{

extern const SimpleNodeStaticValues SNIP_STATIC_DATA = {4, "OpenMRN",
    "Test IO Board - Tiva Launchpad 123", "ek-tm4c123gxl", "1.01"};

/// Defines the main segment in the configuration CDI. This is laid out at
/// origin 128 to give space for the ACDI user data at the beginning.
BEGIN_GROUP(
    IoBoardSegment, base, Segment(MemoryConfigDefs::SPACE_CONFIG), Offset(128));
EXTEND_GROUP(
    IoBoardSegment, base, blinker, ConsumerConfig, Name("Blinker LED"));
END_GROUP(IoBoardSegment, blinker);

/// The main structure of the CDI. ConfigDef is the symbol we use in main.cxx
/// to refer to the configuration defined here.
BEGIN_GROUP(ConfigDef, base, MainCdi());
/// Adds the <identification> tag with the values from SNIP_STATIC_DATA above.
EXTEND_GROUP(ConfigDef, base, ident, Identification);
/// Adds an <acdi> tag.
EXTEND_GROUP(ConfigDef, ident, acdi, Acdi);
/// Adds a segment for changing the values in the ACDI user-defined
/// space. UserInfoSegment is defined in the system header.
EXTEND_GROUP(ConfigDef, acdi, userinfo, UserInfoSegment);
EXTEND_GROUP(ConfigDef, userinfo, seg, IoBoardSegment);
/// To end the group we have to declare what was the last entry.
END_GROUP(ConfigDef, seg);

} // namespace nmranet
