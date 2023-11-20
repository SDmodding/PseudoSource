// File Line: 14
// RVA: 0x146B470
__int64 Render::_dynamic_initializer_for__gFXForceManager__()
{
  return atexit(Render::_dynamic_atexit_destructor_for__gFXForceManager__);
}

// File Line: 18
// RVA: 0x1C1180
void __fastcall Render::FXForceComponent::FXForceComponent(Render::FXForceComponent *this)
{
  Render::FXForceComponent *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax
  char v3; // cl
  UFG::qVector4 v4; // xmm1
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm3

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXForceComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  v3 = tweakablesAdded;
  if ( !tweakablesAdded )
    v3 = 1;
  tweakablesAdded = v3;
  v4 = UFG::qMatrix44::msIdentity.v1;
  v5 = UFG::qMatrix44::msIdentity.v2;
  v6 = UFG::qMatrix44::msIdentity.v3;
  v1->mTransform.v0 = UFG::qMatrix44::msIdentity.v0;
  v1->mTransform.v1 = v4;
  v1->mTransform.v2 = v5;
  v1->mTransform.v3 = v6;
}

// File Line: 29
// RVA: 0x1C35C0
void __fastcall Render::FXForceComponent::~FXForceComponent(Render::FXForceComponent *this)
{
  Render::FXForceComponent *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v8; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXForceComponent::`vftable;
  v2 = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v2);
  v4 = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v4);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v6 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
}

// File Line: 35
// RVA: 0x1CE4E0
void __fastcall Render::FXForceComponent::Init(Render::FXForceComponent *this, unsigned int settingsId)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  Render::FXForceComponent *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  v2 = `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result;
  v3 = settingsId;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0x433ED8DFu);
    `UFG::qGetResourceInventory<Render::FXForceSettings>::`2::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettingsHandle.mPrev, 0x433ED8DFu, v3, v2);
}

// File Line: 65
// RVA: 0x1D8E10
void __fastcall Render::FXForceComponent::Update(Render::FXForceComponent *this, UFG::qVector3 *cam_pos, float simTime)
{
  Render::FXForceComponent *v3; // rbp
  UFG::qResourceData *v4; // r14
  Render::DebugDrawContext *v5; // rbx
  Render::DebugDrawContext *v6; // rsi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  unsigned __int64 v12; // rcx
  Render::FXForce *v13; // rax
  UFG::qColour colour; // [rsp+38h] [rbp-40h]
  UFG::qString v15; // [rsp+48h] [rbp-30h]

  v3 = this;
  v4 = this->mSettingsHandle.mData;
  if ( v4 )
  {
    Render::FXComponentInstance::GetBasis((Render::FXComponentInstance *)&this->vfptr, &this->mTransform);
    if ( Render::FXForceComponent::sDebugDrawsEnabled )
    {
      v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
      v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
      colour.r = 1.0;
      colour.g = 1.0;
      colour.b = 0.0;
      colour.a = 1.0;
      Render::DebugDrawContext::DrawSphere(
        v5,
        (UFG::qVector3 *)&v3->mTransform.v3,
        *(const float *)v4[1].mNode.mChild,
        &colour,
        &UFG::qMatrix44::msIdentity,
        0i64);
      UFG::qString::qString(&v15);
      UFG::qString::Format(&v15, "Intensity:%.2f\n", *(float *)&v4[1].mNode.mParent);
      Render::DebugDrawContext::DrawText(v6, (UFG::qVector3 *)&v3->mTransform.v3, &UFG::qColour::White, v15.mData);
      UFG::qString::~qString(&v15);
    }
    v7 = *(float *)&v4[1].mNode.mParent;
    v8 = *((float *)&v4[1].mNode.mParent + 1);
    v9 = *(float *)v4[1].mNode.mChild;
    v10 = v3->mTransform.v3.y;
    v11 = v3->mTransform.v3.z;
    if ( Render::gFXForceManager.mNumForces < 60 )
    {
      v12 = Render::gFXForceManager.mNumForces;
      v13 = Render::gFXForceManager.mForceList;
      Render::gFXForceManager.mForceList[v12].position.x = v3->mTransform.v3.x;
      v13[v12].position.y = v10;
      v13[v12].position.z = v11;
      v13[v12].intensity = v7;
      v13[v12].radMin = v8;
      v13[v12].radMax = v9;
      ++Render::gFXForceManager.mNumForces;
    }
  }
}

