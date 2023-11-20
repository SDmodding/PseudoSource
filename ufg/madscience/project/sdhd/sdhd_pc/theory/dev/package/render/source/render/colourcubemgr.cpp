// File Line: 93
// RVA: 0x489B0
void __fastcall UFG::ColourCubeMgr::Init(unsigned int colour_cube_uid)
{
  unsigned int v1; // ebx
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceInventory *v3; // rax

  v1 = colour_cube_uid;
  v2 = UFG::qResourceWarehouse::Instance();
  v3 = UFG::qResourceWarehouse::GetInventory(v2, 0x8B43FABF);
  UFG::ColourCubeMgr::mColourCubeBlend = (Illusion::Texture *)v3->vfptr->Get(v3, v1);
  UFG::ColourCubeMgr::mEnableBlending = 0;
  UFG::ColourCubeMgr::mActiveColourCubes.mNumEntries = 0;
}

// File Line: 122
// RVA: 0x48A00
void __fastcall UFG::ColourCubeArray::Remove(UFG::ColourCubeArray *this, unsigned int colour_cube_uid)
{
  unsigned int v2; // er10
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

