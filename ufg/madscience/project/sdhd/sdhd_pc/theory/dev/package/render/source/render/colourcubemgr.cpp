// File Line: 93
// RVA: 0x489B0
void __fastcall UFG::ColourCubeMgr::Init(unsigned int colour_cube_uid)
{
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *Inventory; // rax

  v2 = UFG::qResourceWarehouse::Instance();
  Inventory = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
  UFG::ColourCubeMgr::mColourCubeBlend = (Illusion::Texture *)Inventory->vfptr->Get(Inventory, colour_cube_uid);
  UFG::ColourCubeMgr::mEnableBlending = 0;
  UFG::ColourCubeMgr::mActiveColourCubes.mNumEntries = 0;
}

// File Line: 122
// RVA: 0x48A00
void __fastcall UFG::ColourCubeArray::Remove(UFG::ColourCubeArray *this, unsigned int colour_cube_uid)
{
  unsigned int v2; // r10d
  int v3; // eax

  v2 = 0;
  v3 = 0;
  if ( this->mNumEntries )
  {
    while ( this->mUID[v3] != colour_cube_uid )
    {
      if ( ++v3 >= this->mNumEntries )
        return;
    }
    if ( v3 )
      v2 = v3 - 1;
    this->mNumEntries = v2;
  }
}

// File Line: 160
// RVA: 0x14547A0
__int64 UFG::_dynamic_initializer_for__gHash_SIMPLE__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  gHash_SIMPLE = result;
  return result;
}

