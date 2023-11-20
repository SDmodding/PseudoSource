// File Line: 310
// RVA: 0x276E0
void __fastcall Render::rIrradianceVolume::rIrradianceVolume(Render::rIrradianceVolume *this, MemImageLoadFlag f)
{
  Render::rIrradianceVolume *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&Render::rIrradianceVolume::`vftable';
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTexture0);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mTexture1);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mTexture2);
}

// File Line: 313
// RVA: 0x277A0
void __fastcall Render::rIrradianceVolume::rIrradianceVolume(Render::rIrradianceVolume *this)
{
  Render::rIrradianceVolume *v1; // rdi
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v2; // rcx
  const char *v3; // rax
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v4; // rcx
  const char *v5; // rax
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax

  v1 = this;
  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>((UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&Render::rIrradianceVolume::`vftable';
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTexture0.mPrev);
  v3 = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v2);
  v1->mTexture0.mTypeUID = UFG::qStringHash64(v3, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTexture1.mPrev);
  v5 = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v4);
  v1->mTexture1.mTypeUID = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTexture2.mPrev);
  v7 = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v6);
  v1->mTexture2.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
}

