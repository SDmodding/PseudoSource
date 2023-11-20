// File Line: 137
// RVA: 0x154150
void __fastcall UFG::PartDefinition::PartDefinition(UFG::PartDefinition *this, MemImageLoadFlag f)
{
  UFG::PartDefinition *v2; // rdi
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  unsigned int v5; // ebx
  signed __int64 v6; // rcx
  const char *v7; // rdx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v8; // [rsp+60h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v5 = 0;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v8 = &this->mHandles;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartDefinition::`vftable;
  this->mName.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mModelAsset);
  v2->mCompositeData.mDiffuseChannelDefaults.mData.mFlags = 2;
  v2->mCompositeData.mSpecularChannelDefaults.mData.mFlags = 2;
  v2->mTextureAlternates.mData.mFlags = 2;
  v2->mTintColours.mData.mFlags = 2;
  if ( v2->mTextureAlternates.mData.mNumItems > 0 )
  {
    do
    {
      v6 = (signed __int64)&v2->mTextureAlternates.mData.mItems[v5];
      if ( v6 )
      {
        *(_DWORD *)(v6 + 20) = 2;
        *(_DWORD *)(v6 + 36) = 2;
        *(_DWORD *)(v6 + 60) = 2;
        *(_DWORD *)(v6 + 76) = 2;
        if ( *(_DWORD *)(v6 + 16) )
          v7 = *(const char **)(v6 + 8);
        else
          v7 = &customWorldMapCaption;
        UFG::qSymbolUC::set_from_cstr((UFG::qSymbolUC *)v6, v7);
      }
      ++v5;
    }
    while ( v5 < v2->mTextureAlternates.mData.mNumItems );
  }
}

// File Line: 181
// RVA: 0x1545D0
void __fastcall UFG::PartTemplate::PartTemplate(UFG::PartTemplate *this, MemImageLoadFlag f)
{
  UFG::PartTemplate *v2; // rdi
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+60h] [rbp+18h]
  UFG::PartTemplate::Slot *v6; // [rsp+60h] [rbp+18h]

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartTemplate,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplate::`vftable;
  v6 = &this->mSlotTree;
  v6->mName.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mSlotTree.mDefaultPart);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v6->mCameraSettings);
  v6->mChildren.mData.mFlags = 2;
  v2->mScalingRegions.mData.mFlags = 2;
}

// File Line: 274
// RVA: 0x154770
void __fastcall UFG::PartTemplateInstance::PartTemplateInstance(UFG::PartTemplateInstance *this)
{
  UFG::PartTemplateInstance *v1; // rdi

  v1 = this;
  UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject> *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable;
  v1->mCompositeDirty = 1;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTemplate.mPrev);
  v1->mTemplate.mTypeUID = UFG::qStringHash64("UFG::PartTemplate", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mScalingPreset.mPrev);
  v1->mScalingPreset.mTypeUID = UFG::qStringHash64("UFG::ScalingPreset", 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&v1->mSlots.mData.mNumItems = 0i64;
  v1->mSlots.mData.mItems = 0i64;
  *(_QWORD *)&v1->mScalingRegions.mData.mNumItems = 0i64;
  v1->mScalingRegions.mData.mItems = 0i64;
  v1->mTextureData = 0i64;
}

// File Line: 285
// RVA: 0x1546A0
void __fastcall UFG::PartTemplateInstance::PartTemplateInstance(UFG::PartTemplateInstance *this, MemImageLoadFlag f)
{
  UFG::PartTemplateInstance *v2; // rbx
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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable;
  this->mCompositeDirty = 1;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTemplate);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mScalingPreset);
  v2->mSlots.mData.mFlags = 2;
  v2->mScalingRegions.mData.mFlags = 2;
  v2->mTextureData = 0i64;
}

