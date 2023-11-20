// File Line: 27
// RVA: 0x146B670
__int64 Render::_dynamic_initializer_for__gGeoSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gGeoSettingsInventory.vfptr,
    "GeoSettingsInventory",
    0xF1734D8E,
    0x52A8963Au,
    0,
    0);
  Render::gGeoSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::GeoSettingsInventory::`vftable';
  return atexit(Render::_dynamic_atexit_destructor_for__gGeoSettingsInventory__);
}

// File Line: 35
// RVA: 0x1C69B0
void __fastcall UFG::NISSpatialDataInventory::Add(Render::GeoSettingsInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  Render::GeoSettingsInventory *v3; // rdi

  v2 = data;
  v3 = this;
  if ( data )
    UFG::qResourceData::qResourceData(data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 41
// RVA: 0x1D25D0
void __fastcall Render::GeoSettingsInventory::Remove(Render::GeoSettingsInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // [rsp+48h] [rbp+10h]

  v2 = data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, data);
  v5 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v3 = v2->mResourceHandles.mNode.mPrev;
  v4 = v2->mResourceHandles.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

// File Line: 49
// RVA: 0x146B650
__int64 Render::_dynamic_initializer_for__gGeoManager__()
{
  return atexit(Render::_dynamic_atexit_destructor_for__gGeoManager__);
}

// File Line: 74
// RVA: 0x1C6DE0
void __fastcall Render::GeoManager::AddGeo(Render::GeoManager *this, UFG::qMatrix44 *transform, Illusion::ModelHandle *model, UFG::qColour *colorTint)
{
  __int64 v4; // rbp
  UFG::qMatrix44 *v5; // r14
  unsigned int v6; // edx
  unsigned int v7; // ebx
  UFG::qColour *v8; // rsi
  Illusion::ModelHandle *v9; // r15
  Render::GeoManager *v10; // rdi
  unsigned int v11; // edx
  UFG::qVector4 v12; // xmm3
  signed __int64 v13; // rbx
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qResourceInventory *v16; // rax
  unsigned int v17; // edi
  UFG::qResourceWarehouse *v18; // rax

  v4 = this->mGeos.size;
  v5 = transform;
  v6 = this->mGeos.capacity;
  v7 = v4 + 1;
  v8 = colorTint;
  v9 = model;
  v10 = this;
  if ( (signed int)v4 + 1 > v6 )
  {
    if ( v6 )
      v11 = 2 * v6;
    else
      v11 = 1;
    for ( ; v11 < v7; v11 *= 2 )
      ;
    if ( v11 - v7 > 0x10000 )
      v11 = v4 + 65537;
    UFG::qArray<Render::GeoManager::GeoEntry,0>::Reallocate(&this->mGeos, v11, "qArray.GeoManager::AddGeo");
  }
  v10->mGeos.size = v7;
  v12 = v5->v1;
  v13 = (signed __int64)&v10->mGeos.p[v4];
  v14 = v5->v2;
  v15 = v5->v3;
  *(UFG::qVector4 *)v13 = v5->v0;
  *(UFG::qVector4 *)(v13 + 16) = v12;
  *(UFG::qVector4 *)(v13 + 32) = v14;
  *(UFG::qVector4 *)(v13 + 48) = v15;
  v16 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  v17 = v9->mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v16;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v13 + 64), 0xA2ADCD77, v17, v16);
  *(float *)(v13 + 96) = v8->r;
  *(float *)(v13 + 100) = v8->g;
  *(float *)(v13 + 104) = v8->b;
  *(float *)(v13 + 108) = v8->a;
}

// File Line: 82
// RVA: 0x1D4760
void __fastcall Render::GeoManager::Render(Render::GeoManager *this, Render::View *view, Render::eFXDrawPass pass, float simTime)
{
  Render::View *v4; // r14
  Render::GeoManager *v5; // rdi
  unsigned int v6; // ebx
  char *v7; // rax
  signed __int64 v8; // rbp
  char *v9; // rsi
  _DWORD *v10; // rdx
  unsigned int v11; // er15
  Illusion::StateValues *v12; // rax

  v4 = view;
  v5 = this;
  v6 = 0;
  if ( this->mGeos.size )
  {
    do
    {
      v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      v8 = v6;
      v9 = v7;
      v10 = (_DWORD *)&v5->mGeos.p[v8].mTransform.v0.x;
      *(_DWORD *)v7 = v10[24];
      *((_DWORD *)v7 + 1) = v10[25];
      *((_DWORD *)v7 + 2) = v10[26];
      *((_DWORD *)v7 + 3) = v10[27];
      *((_DWORD *)v7 + 4) = LODWORD(UFG::qColour::White.r);
      *((_DWORD *)v7 + 5) = LODWORD(UFG::qColour::White.g);
      *((_DWORD *)v7 + 6) = LODWORD(UFG::qColour::White.b);
      *((_DWORD *)v7 + 7) = LODWORD(UFG::qColour::White.a);
      v11 = SLOWORD(v5->mSceneryInstanceStateParamIndex);
      v12 = Render::View::GetStateValues(v4);
      if ( v11 >= 0x40 )
        v12->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v11 - 64);
      else
        v12->mSetValueMask.mFlags[0] |= 1i64 << v11;
      v12->mParamValues[(signed __int16)v11] = v9;
      Render::View::Draw(v4, &v5->mGeos.p[v8].mModel, &v5->mGeos.p[v8].mTransform, 0);
      ++v6;
    }
    while ( v6 < v5->mGeos.size );
  }
}

