// File Line: 15
// RVA: 0x1C3130
void __fastcall Render::DecalInstance::~DecalInstance(Render::DecalInstance *this)
{
  Render::DecalInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::DecalInstance::`vftable;
  v2 = (UFG::qResourceHandle *)&this->mSettingsHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = v3;
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

