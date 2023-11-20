// File Line: 27
// RVA: 0x15ABD50
__int64 UFG::_dynamic_initializer_for__gScreenInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gScreenInventory.vfptr,
    "UIScreenInventory",
    0x442A39D9u,
    0x442A39D9u,
    0,
    0);
  UFG::gScreenInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::UIScreenInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gScreenInventory__);
}

