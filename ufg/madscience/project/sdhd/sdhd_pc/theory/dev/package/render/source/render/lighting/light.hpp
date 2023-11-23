// File Line: 310
// RVA: 0x276E0
void __fastcall Render::rIrradianceVolume::rIrradianceVolume(Render::rIrradianceVolume *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&Render::rIrradianceVolume::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTexture0);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTexture1);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTexture2);
}

// File Line: 313
// RVA: 0x277A0
void __fastcall Render::rIrradianceVolume::rIrradianceVolume(Render::rIrradianceVolume *this)
{
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v2; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v4; // rcx
  const char *v5; // rax
  UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax

  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&Render::rIrradianceVolume::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTexture0);
  TypeName = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v2);
  this->mTexture0.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTexture1);
  v5 = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v4);
  this->mTexture1.mTypeUID = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTexture2);
  v7 = UFG::qReflectObjectType<Illusion::rTexture,UFG::qReflectObject>::GetTypeName(v6);
  this->mTexture2.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
}

