#include "nmranet/SimpleNodeInfo.hxx"
#include "nmranet/ConfigRepresentation.hxx"

namespace nmranet {

extern const SimpleNodeStaticValues SNIP_STATIC_DATA = {
    4,               "OpenMRN", "Test IO Board - Tiva Launchpad 123",
    "ek-tm4c123gxl", "1.01"};

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
/// Closes the CDI declaration.
CDI_GROUP_END();

}  // namespace nmranet
