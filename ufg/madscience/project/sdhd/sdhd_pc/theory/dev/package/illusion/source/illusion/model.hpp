// File Line: 447
// RVA: 0x8CF80
void __fastcall Illusion::Mesh::Mesh(Illusion::Mesh *this)
{
  UFG::qResourceHandle::qResourceHandle(&this->mMaterialHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mVertexDeclHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mIndexBufferHandle);
  `eh vector constructor iterator(
    this->mVertexBufferHandles,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
}

// File Line: 528
// RVA: 0x8CFF0
void __fastcall Illusion::Model::Model(Illusion::Model *this)
{
  UFG::qResourceData::qResourceData(&this->UFG::qResourceData);
  UFG::qResourceHandle::qResourceHandle(&this->mMaterialTableHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mBonePaletteHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mMorphTargetsHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mLocatorsHandle);
}

