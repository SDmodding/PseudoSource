// File Line: 14
// RVA: 0x146B470
__int64 Render::_dynamic_initializer_for__gFXForceManager__()
{
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFXForceManager__);
}

// File Line: 18
// RVA: 0x1C1180
void __fastcall Render::FXForceComponent::FXForceComponent(Render::FXForceComponent *this)
{
  char v2; // cl
  UFG::qVector4 v3; // xmm1
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm3

  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXForceComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  v2 = tweakablesAdded;
  if ( !tweakablesAdded )
    v2 = 1;
  tweakablesAdded = v2;
  v3 = UFG::qMatrix44::msIdentity.v1;
  v4 = UFG::qMatrix44::msIdentity.v2;
  v5 = UFG::qMatrix44::msIdentity.v3;
  this->mTransform.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mTransform.v1 = v3;
  this->mTransform.v2 = v4;
  this->mTransform.v3 = v5;
}

// File Line: 29
// RVA: 0x1C35C0
void __fastcall Render::FXForceComponent::~FXForceComponent(Render::FXForceComponent *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXForceComponent::`vftable;
  Inventory = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  v4 = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = v4;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, v4);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 35
// RVA: 0x1CE4E0
void __fastcall Render::FXForceComponent::Init(Render::FXForceComponent *this, unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0x433ED8DFu, settingsId, Inventory);
}

// File Line: 65
// RVA: 0x1D8E10
void __fastcall Render::FXForceComponent::Update(Render::FXForceComponent *this, UFG::qVector3 *cam_pos, float simTime)
{
  UFG::qResourceData *mData; // r14
  Render::DebugDrawContext *Context; // rbx
  Render::DebugDrawContext *v6; // rsi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float y; // xmm4_4
  float z; // xmm5_4
  unsigned __int64 mNumForces; // rcx
  Render::FXForce *mForceList; // rax
  UFG::qColour colour; // [rsp+38h] [rbp-40h] BYREF
  UFG::qString v15; // [rsp+48h] [rbp-30h] BYREF

  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    Render::FXComponentInstance::GetBasis(this, &this->mTransform);
    if ( Render::FXForceComponent::sDebugDrawsEnabled )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              2u);
      v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 0.0;
      colour.a = 1.0;
      Render::DebugDrawContext::DrawSphere(
        Context,
        (UFG::qVector3 *)&this->mTransform.v3,
        *(float *)mData[1].mNode.mChild,
        &colour,
        &UFG::qMatrix44::msIdentity,
        0i64);
      UFG::qString::qString(&v15);
      UFG::qString::Format(&v15, "Intensity:%.2f\n", *(float *)&mData[1].mNode.mParent);
      Render::DebugDrawContext::DrawText(v6, (UFG::qVector3 *)&this->mTransform.v3, &UFG::qColour::White, v15.mData);
      UFG::qString::~qString(&v15);
    }
    v7 = *(float *)&mData[1].mNode.mParent;
    v8 = *((float *)&mData[1].mNode.mParent + 1);
    v9 = *(float *)mData[1].mNode.mChild;
    y = this->mTransform.v3.y;
    z = this->mTransform.v3.z;
    if ( Render::gFXForceManager.mNumForces < 60 )
    {
      mNumForces = Render::gFXForceManager.mNumForces;
      mForceList = Render::gFXForceManager.mForceList;
      Render::gFXForceManager.mForceList[mNumForces].position.x = this->mTransform.v3.x;
      mForceList[mNumForces].position.y = y;
      mForceList[mNumForces].position.z = z;
      mForceList[mNumForces].intensity = v7;
      mForceList[mNumForces].radMin = v8;
      mForceList[mNumForces].radMax = v9;
      ++Render::gFXForceManager.mNumForces;
    }
  }
}

