// File Line: 17
// RVA: 0x1C3E50
void __fastcall Render::GeoInstance::~GeoInstance(Render::GeoInstance *this)
{
  Render::GeoInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v8; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v9; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::GeoInstance::`vftable';
  v2 = (UFG::qResourceHandle *)&this->mModelHandle.mPrev;
  v3 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v5 = `UFG::qGetResourceInventory<Render::GeoSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::GeoSettings>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xF1734D8E);
    `UFG::qGetResourceInventory<Render::GeoSettings>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev, v5);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSettingsHandle.mPrev);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable';
  v7 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

