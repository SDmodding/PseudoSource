// File Line: 27
// RVA: 0x146B670
__int64 Render::_dynamic_initializer_for__gGeoSettingsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gGeoSettingsInventory,
    "GeoSettingsInventory",
    0xF1734D8E,
    0x52A8963Au,
    0,
    0);
  Render::gGeoSettingsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::GeoSettingsInventory::`vftable;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gGeoSettingsInventory__);
}

// File Line: 35
// RVA: 0x1C69B0
void __fastcall UFG::NISSpatialDataInventory::Add(Render::GeoSettingsInventory *this, UFG::qResourceData *data)
{
  if ( data )
    UFG::qResourceData::qResourceData(data);
  UFG::qResourceInventory::Add(this, data);
}

// File Line: 41
// RVA: 0x1D25D0
void __fastcall Render::GeoSettingsInventory::Remove(Render::GeoSettingsInventory *this, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&data->mResourceHandles);
  mPrev = data->mResourceHandles.mNode.mPrev;
  mNext = data->mResourceHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  data->mResourceHandles.mNode.mPrev = &data->mResourceHandles.mNode;
  data->mResourceHandles.mNode.mNext = &data->mResourceHandles.mNode;
}

// File Line: 49
// RVA: 0x146B650
__int64 Render::_dynamic_initializer_for__gGeoManager__()
{
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gGeoManager__);
}

// File Line: 74
// RVA: 0x1C6DE0
void __fastcall Render::GeoManager::AddGeo(
        Render::GeoManager *this,
        UFG::qMatrix44 *transform,
        Illusion::ModelHandle *model,
        UFG::qColour *colorTint)
{
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v11; // edx
  UFG::qVector4 v12; // xmm3
  Render::GeoManager::GeoEntry *v13; // rbx
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mNameUID; // edi
  UFG::qResourceWarehouse *v18; // rax

  size = this->mGeos.size;
  capacity = this->mGeos.capacity;
  v7 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v11 = 2 * capacity;
    else
      v11 = 1;
    for ( ; v11 < v7; v11 *= 2 )
      ;
    if ( v11 - v7 > 0x10000 )
      v11 = size + 65537;
    UFG::qArray<Render::GeoManager::GeoEntry,0>::Reallocate(&this->mGeos, v11, "qArray.GeoManager::AddGeo");
  }
  this->mGeos.size = v7;
  v12 = transform->v1;
  v13 = &this->mGeos.p[size];
  v14 = transform->v2;
  v15 = transform->v3;
  v13->mTransform.v0 = transform->v0;
  v13->mTransform.v1 = v12;
  v13->mTransform.v2 = v14;
  v13->mTransform.v3 = v15;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  mNameUID = model->mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v13->mModel, 0xA2ADCD77, mNameUID, Inventory);
  v13->mColorTint.r = colorTint->r;
  v13->mColorTint.g = colorTint->g;
  v13->mColorTint.b = colorTint->b;
  v13->mColorTint.a = colorTint->a;
}

// File Line: 82
// RVA: 0x1D4760
void __fastcall Render::GeoManager::Render(
        Render::GeoManager *this,
        Render::View *view,
        Render::eFXDrawPass pass,
        float simTime)
{
  unsigned int i; // ebx
  __int64 v7; // rbp
  char *v8; // rsi
  Render::GeoManager::GeoEntry *v9; // rdx
  unsigned int mSceneryInstanceStateParamIndex_low; // r15d
  Illusion::StateValues *StateValues; // rax

  for ( i = 0; i < this->mGeos.size; ++i )
  {
    v7 = i;
    v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
    v9 = &this->mGeos.p[v7];
    *(float *)v8 = v9->mColorTint.r;
    *((_DWORD *)v8 + 1) = LODWORD(v9->mColorTint.g);
    *((_DWORD *)v8 + 2) = LODWORD(v9->mColorTint.b);
    *((_DWORD *)v8 + 3) = LODWORD(v9->mColorTint.a);
    *((UFG::qColour *)v8 + 1) = UFG::qColour::White;
    mSceneryInstanceStateParamIndex_low = SLOWORD(this->mSceneryInstanceStateParamIndex);
    StateValues = Render::View::GetStateValues(view);
    if ( mSceneryInstanceStateParamIndex_low >= 0x40 )
      StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mSceneryInstanceStateParamIndex_low - 64);
    else
      StateValues->mSetValueMask.mFlags[0] |= 1i64 << mSceneryInstanceStateParamIndex_low;
    StateValues->mParamValues[(__int16)mSceneryInstanceStateParamIndex_low] = v8;
    Render::View::Draw(view, &this->mGeos.p[v7].mModel, &this->mGeos.p[v7].mTransform, 0, 0i64);
  }
}

