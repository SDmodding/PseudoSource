// File Line: 447
// RVA: 0x8CF80
void __fastcall Illusion::Mesh::Mesh(Illusion::Mesh *this)
{
  Illusion::Mesh *v1; // rbx

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mMaterialHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mVertexDeclHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mIndexBufferHandle.mPrev);
  `eh vector constructor iterator'(
    v1->mVertexBufferHandles,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
}

// File Line: 528
// RVA: 0x8CFF0
void __fastcall Illusion::Model::Model(Illusion::Model *this)
{
  Illusion::Model *v1; // rbx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mMaterialTableHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mBonePaletteHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mMorphTargetsHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mLocatorsHandle.mPrev);
}

