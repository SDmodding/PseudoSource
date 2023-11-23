// File Line: 137
// RVA: 0x154150
void __fastcall UFG::PartDefinition::PartDefinition(UFG::PartDefinition *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  unsigned int v4; // ebx
  UFG::PartDefinition::TextureAlternate *v5; // rcx
  const char *mItems; // rdx

  mUID = this->mBaseNode.mUID;
  v4 = 0;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartDefinition::`vftable;
  this->mName.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mModelAsset);
  this->mCompositeData.mDiffuseChannelDefaults.mData.mFlags = 2;
  this->mCompositeData.mSpecularChannelDefaults.mData.mFlags = 2;
  this->mTextureAlternates.mData.mFlags = 2;
  this->mTintColours.mData.mFlags = 2;
  if ( this->mTextureAlternates.mData.mNumItems )
  {
    do
    {
      v5 = &this->mTextureAlternates.mData.mItems[v4];
      if ( v5 )
      {
        v5->mName.mText.mData.mFlags = 2;
        v5->mTextures.mData.mFlags = 2;
        v5->mCompositeData.mDiffuseChannelDefaults.mData.mFlags = 2;
        v5->mCompositeData.mSpecularChannelDefaults.mData.mFlags = 2;
        if ( v5->mName.mText.mData.mNumItems )
          mItems = v5->mName.mText.mData.mItems;
        else
          mItems = &customCaption;
        UFG::qSymbolUC::set_from_cstr(&v5->mId, mItems);
      }
      ++v4;
    }
    while ( v4 < this->mTextureAlternates.mData.mNumItems );
  }
}

// File Line: 181
// RVA: 0x1545D0
void __fastcall UFG::PartTemplate::PartTemplate(UFG::PartTemplate *this, MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  UFG::PartTemplate::Slot *p_mSlotTree; // rbx

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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartTemplate,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplate::`vftable;
  p_mSlotTree = &this->mSlotTree;
  this->mSlotTree.mName.mText.mData.mFlags = 2;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mSlotTree.mDefaultPart);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&p_mSlotTree->mCameraSettings);
  p_mSlotTree->mChildren.mData.mFlags = 2;
  this->mScalingRegions.mData.mFlags = 2;
}

// File Line: 274
// RVA: 0x154770
void __fastcall UFG::PartTemplateInstance::PartTemplateInstance(UFG::PartTemplateInstance *this)
{
  UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>(this);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable;
  this->mCompositeDirty = 1;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mTemplate);
  this->mTemplate.mTypeUID = UFG::qStringHash64("UFG::PartTemplate", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mScalingPreset);
  this->mScalingPreset.mTypeUID = UFG::qStringHash64("UFG::ScalingPreset", 0xFFFFFFFFFFFFFFFFui64);
  *(_QWORD *)&this->mSlots.mData.mNumItems = 0i64;
  this->mSlots.mData.mItems = 0i64;
  *(_QWORD *)&this->mScalingRegions.mData.mNumItems = 0i64;
  this->mScalingRegions.mData.mItems = 0i64;
  this->mTextureData = 0i64;
}

// File Line: 285
// RVA: 0x1546A0
void __fastcall UFG::PartTemplateInstance::PartTemplateInstance(UFG::PartTemplateInstance *this, MemImageLoadFlag f)
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
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable;
  this->mCompositeDirty = 1;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mTemplate);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mScalingPreset);
  this->mSlots.mData.mFlags = 2;
  this->mScalingRegions.mData.mFlags = 2;
  this->mTextureData = 0i64;
}

