#include "nmranet/SimpleNodeInfo.hxx"
#include "nmranet/ConfigRepresentation.hxx"

namespace nmranet {

extern const SimpleNodeStaticValues SNIP_STATIC_DATA = {
    4,               "OpenMRN", "Test IO Board - Tiva Launchpad 123",
    "ek-tm4c123gxl", "1.01"};

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
/// To end the group we have to declare what was the last entry.
END_GROUP(ConfigDef, userinfo);

}  // namespace nmranet
