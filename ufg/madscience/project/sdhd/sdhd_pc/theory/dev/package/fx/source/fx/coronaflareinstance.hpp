// File Line: 13
// RVA: 0x1C0EB0
void __fastcall Render::CoronaFlareInstance::CoronaFlareInstance(Render::CoronaFlareInstance *this)
{
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v1; // rax

  v1 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::CoronaFlareInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mCoronaFlare.mSettings.mPrev);
}

// File Line: 14
// RVA: 0x1C2ED0
void __fastcall Render::CoronaFlareInstance::~CoronaFlareInstance(Render::CoronaFlareInstance *this)
{
  Render::CoronaFlareInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::CoronaFlareInstance::`vftable;
  v2 = (UFG::qResourceHandle *)&this->mCoronaFlare.mSettings.mPrev;
  v3 = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xB76CCFB8);
    `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v5 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

