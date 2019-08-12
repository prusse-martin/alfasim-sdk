#ifndef _H_ASIM_SDK_COMMON
#define _H_ASIM_SDK_COMMON

enum error_code
{
    REFERENCE_NOT_SET=-8,
    UNKNOWN_REFERENCE_TYPE=-7,
    OUT_OF_BOUNDS=-6,
    UNKNOWN_CONTEXT=-5,
    NOT_AVAILABLE_DATA=-4,
    BUFFER_SIZE_INSUFFICIENT=-3,
    UNDEFINED_DATA=-2,
    NOT_IMPLEMENTED=-1,
    OK = 0
};

enum GridScope
{
    CENTER=0,
    FACE=1
};

enum MultiFieldDescriptionScope
{
    MIXTURE=0,
    GLOBAL=0,
    FIELD=1,
    LAYER=2,
    PHASE=3
};

enum TimestepScope
{
    CURRENT=0,
    PREVIOUS=1
};

enum StateVariable {
    RHO, // Density
    MU, // Viscosity
    CP, // Heat Capacity
    DRHO_DP, // Partial derivative of density in relation to pressure
    DRHO_DT, // Partial derivative of density in relation to temperature
    H, // Enthalpy
    K, // Thermal Conductivity
    SIGMA // Interfacial tension
};

enum WallLayerProperty {
    THICKNESS=0,
    DENSITY=1,
    THERMAL_CONDUCTIVITY=2,
    HEAT_CAPACITY=3,
    INNER_EMISSIVITY=4,
    OUTER_EMISSIVITY=5,
    EXPANSION=6,
    VISCOSITY=7
};

struct VariableScope
{
    enum GridScope grid_scope;
    enum MultiFieldDescriptionScope mfd_scope;
    enum TimestepScope ts_scope;
};

enum sdk_load_error_code {
    SDK_DLL_PATH_TOO_LONG=-2,
    SDK_ALREADY_OPEN_ERROR=-1,
    SDK_OK=0
};

#define FIELD_GAS "gas"
#define FIELD_LIQUID "liquid"
#define FIELD_WATER "water"
#define FIELD_WATER_DROPLET_IN_LIQUID "water_in_liquid_droplet"
#define FIELD_DROPLET "droplet"
#define FIELD_BUBBLE "bubble"

#define PHASE_GAS "gas"
#define PHASE_LIQUID "liquid"
#define PHASE_WATER "water"

#define LAYER_GAS "gas"
#define LAYER_LIQUID "liquid"
#define LAYER_WATER "water"

#endif
