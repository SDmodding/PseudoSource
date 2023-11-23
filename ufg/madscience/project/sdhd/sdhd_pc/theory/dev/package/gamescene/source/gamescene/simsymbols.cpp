// File Line: 31
// RVA: 0x1474070
__int64 dynamic_initializer_for__SimSym_InventoryType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("InventoryType", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&SimSym_InventoryType, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimSym_InventoryType__);
}

// File Line: 32
// RVA: 0x14726F0
__int64 dynamic_initializer_for__SimSymX_propset_componentVehicleProperties__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-VehicleProperties", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&SimSymX_propset_componentVehicleProperties, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SimSymX_propset_componentVehicleProperties__);
}

