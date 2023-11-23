// File Line: 16
// RVA: 0x1454360
__int64 Render::_dynamic_initializer_for__gTerrainDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gTerrainDataInventory,
    "TerrainDataInventory",
    0x392C3181u,
    0xC462DD28,
    0,
    0);
  Render::gTerrainDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::TerrainDataInventory::`vftable;
  Render::gTerrainDataInventory.mAddTerrainDataCallback = 0i64;
  Render::gTerrainDataInventory.mRemoveTerrainDataCallback = 0i64;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTerrainDataInventory__);
}

