// File Line: 56
// RVA: 0x1C4A80
void __fastcall Illusion::ShaderParam::operator delete(void *ptr)
{
  operator delete[](ptr);
}

// File Line: 60
// RVA: 0x1C2C10
void __fastcall Render::AudioFXInstance::~AudioFXInstance(Render::AudioFXInstance *this)
{
  Render::AudioFXInstance *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v4; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::AudioFXInstance::`vftable;
  UFG::OneShotHandle::Release(&this->mOneShot);
  v2 = `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0xD77CCEB2);
    `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v4 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
}

