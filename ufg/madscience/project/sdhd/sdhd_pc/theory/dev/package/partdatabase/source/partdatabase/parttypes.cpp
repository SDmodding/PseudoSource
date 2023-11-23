// File Line: 14
// RVA: 0x1466C50
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PartDefinition_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory,
    "UFG::PartDefinition",
    v0);
  UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PartDefinition>::`vftable;
  UFG::qReflectInventory<UFG::PartDefinition>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PartDefinition_UFG::qReflectObject_::sInventory__);
}

// File Line: 15
// RVA: 0x1466B70
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PartTemplate_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::PartTemplate,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 16
// RVA: 0x1466DD0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::ScalingPreset_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::ScalingPreset", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory,
    "UFG::ScalingPreset",
    v0);
  UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ScalingPreset>::`vftable;
  UFG::qReflectInventory<UFG::ScalingPreset>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ScalingPreset_UFG::qReflectObject_::sInventory__);
}

// File Line: 17
// RVA: 0x159050
const char *__fastcall UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject> *this)
{
  return "UFG::PartTemplateInstance";
}

// File Line: 50
// RVA: 0x158BC0
UFG::qString *__fastcall UFG::PartDefinition::GetModelFileName(UFG::PartDefinition *this, UFG::qString *result)
{
  const char *Name; // rax

  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::FormatEx(result, "Data\\Parts\\%s.bin", Name);
  return result;
}

// File Line: 55
// RVA: 0x1590A0
UFG::qString *__fastcall UFG::PartDefinition::GetTextureFileName(UFG::PartDefinition *this, UFG::qString *result)
{
  const char *v4; // rax
  const char *Name; // rax
  const char *v6; // rax
  const char *v7; // rax
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-78h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  UFG::qString::qString(result);
  if ( outSettings.mTextureDetailLevel )
  {
    if ( outSettings.mTextureDetailLevel == TEXTURE_DETAIL_MEDIUM )
    {
      Name = UFG::qReflectObject::GetName(this);
      UFG::qString::Format(result, "Data\\Parts\\SD\\%s.perm.bin", Name);
    }
    else if ( outSettings.mTextureDetailLevel == TEXTURE_DETAIL_HIGH )
    {
      v6 = UFG::qReflectObject::GetName(this);
      UFG::qString::Format(result, "Data\\Parts\\HD\\%s.perm.bin", v6);
    }
    else
    {
      v7 = UFG::qReflectObject::GetName(this);
      UFG::qString::Format(result, "Data\\Parts\\%s.perm.bin", v7);
    }
  }
  else
  {
    v4 = UFG::qReflectObject::GetName(this);
    UFG::qString::Format(result, "Data\\Parts\\LD\\%s.perm.bin", v4);
  }
  return result;
}

// File Line: 81
// RVA: 0x158C10
__int64 __fastcall UFG::PartDefinition::GetModelSize(UFG::PartDefinition *this)
{
  UFG::qString v3; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  if ( this->mModelSize )
    return this->mModelSize;
  UFG::PartDefinition::GetModelFileName(this, &result);
  this->mModelSize = PartDatabase_QueryFileSize(result.mData);
  UFG::PartDefinition::GetTextureFileName(this, &v3);
  this->mModelSize += PartDatabase_QueryFileSize(v3.mData);
  UFG::qString::~qString(&v3);
  UFG::qString::~qString(&result);
  return this->mModelSize;
}

// File Line: 108
// RVA: 0x159060
UFG::PartDefinition::TextureAlternate *__fastcall UFG::PartDefinition::GetTextureAlternate(
        UFG::PartDefinition *this,
        UFG::qSymbolUC *textureSet)
{
  unsigned int mUID; // r9d
  unsigned int mNumItems; // r8d
  int v4; // edx
  UFG::PartDefinition::TextureAlternate *result; // rax

  mUID = textureSet->mUID;
  if ( textureSet->mUID == UFG::gNullQSymbolUC.mUID )
    return 0i64;
  mNumItems = this->mTextureAlternates.mData.mNumItems;
  v4 = 0;
  if ( !mNumItems )
    return 0i64;
  for ( result = this->mTextureAlternates.mData.mItems; result->mId.mUID != mUID; ++result )
  {
    if ( ++v4 >= mNumItems )
      return 0i64;
  }
  return result;
}

// File Line: 136
// RVA: 0x158CA0
char *__fastcall UFG::PartTemplate::GetNameFromSlotIDRecursive(
        UFG::PartTemplate *this,
        UFG::qSymbolUC *slotId,
        UFG::PartTemplate::Slot *slot)
{
  char *result; // rax
  int v7; // ebx

  if ( slot->mSlotName.mUID == slotId->mUID )
  {
    if ( slot->mName.mText.mData.mNumItems )
      return slot->mName.mText.mData.mItems;
    else
      return &customCaption;
  }
  else
  {
    v7 = 0;
    if ( slot->mChildren.mData.mNumItems )
    {
      while ( 1 )
      {
        result = (char *)UFG::PartTemplate::GetNameFromSlotIDRecursive(this, slotId, &slot->mChildren.mData.mItems[v7]);
        if ( result )
          break;
        if ( ++v7 >= slot->mChildren.mData.mNumItems )
          return 0i64;
      }
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 159
// RVA: 0x158B00
UFG::qReflectObject *__fastcall UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(
        UFG::PartTemplate *this,
        UFG::qSymbolUC *slotId,
        UFG::PartTemplate::Slot *slot)
{
  UFG::qReflectObject *result; // rax
  int v7; // ebx

  if ( slot->mSlotName.mUID == slotId->mUID )
    return slot->mCameraSettings.mData;
  v7 = 0;
  if ( !slot->mChildren.mData.mNumItems )
    return 0i64;
  while ( 1 )
  {
    result = UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(this, slotId, &slot->mChildren.mData.mItems[v7]);
    if ( result )
      break;
    if ( ++v7 >= slot->mChildren.mData.mNumItems )
      return 0i64;
  }
  return result;
}

// File Line: 183
// RVA: 0x158FC0
UFG::ScalingPreset::RegionValues *__fastcall UFG::ScalingPreset::GetScaleValues(
        UFG::ScalingPreset *this,
        const char *region)
{
  int v2; // edi
  UFG::ScalingPreset::RegionValues *v5; // rbx
  const char *v6; // rdx

  v2 = 0;
  if ( !this->mRegions.mData.mNumItems )
    return 0i64;
  while ( 1 )
  {
    v5 = &this->mRegions.mData.mItems[v2];
    v6 = v5->mName.mText.mData.mNumItems ? v5->mName.mText.mData.mItems : &customCaption;
    if ( !(unsigned int)UFG::qStringCompare(region, v6, -1) )
      break;
    if ( ++v2 >= this->mRegions.mData.mNumItems )
      return 0i64;
  }
  return v5;
}

// File Line: 203
// RVA: 0x1594E0
bool __fastcall UFG::PartTemplateInstance::SlotEntry::IsComposited(UFG::PartTemplateInstance::SlotEntry *this)
{
  bool result; // al
  __int64 mNumItems; // rdx
  UFG::qReflectObject **p_mData; // rcx
  bool v4; // zf

  result = 0;
  if ( this->mBasePart.mPart.mData )
  {
    mNumItems = this->mLayers.mData.mNumItems;
    if ( (_DWORD)mNumItems )
    {
      p_mData = &this->mLayers.mData.mItems->mPart.mData;
      do
      {
        v4 = *p_mData == 0i64;
        p_mData += 10;
        if ( !v4 )
          result = 1;
        --mNumItems;
      }
      while ( mNumItems );
    }
  }
  return result;
}

// File Line: 224
// RVA: 0x1568C0
void __fastcall UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(
        UFG::PartTemplateInstance::PartEntry *this,
        UFG::PartDefinition::CompositeData *compositeData)
{
  __int64 mNumItems; // rsi
  UFG::qReflectArray<UFG::qColour> *p_mDiffuseColours; // rdi
  __int64 v5; // rbx
  __int64 v6; // r8
  UFG::qColour *mItems; // rcx
  float r; // eax
  float *p_r; // rdx

  mNumItems = compositeData->mDiffuseChannelDefaults.mData.mNumItems;
  p_mDiffuseColours = &this->mDiffuseColours;
  if ( (this->mDiffuseColours.mData.mFlags & 2) == 0 )
    operator delete[](p_mDiffuseColours->mData.mItems);
  v5 = 0i64;
  p_mDiffuseColours->mData.mItems = 0i64;
  *(_QWORD *)&p_mDiffuseColours->mData.mNumItems = 0i64;
  UFG::qReflectArray<UFG::qColour>::Resize(p_mDiffuseColours, mNumItems, "qReflectArray.Resize");
  if ( (_DWORD)mNumItems )
  {
    v6 = mNumItems;
    do
    {
      mItems = compositeData->mDiffuseChannelDefaults.mData.mItems;
      r = mItems[v5].r;
      p_r = &p_mDiffuseColours->mData.mItems[v5++].r;
      *p_r = r;
      p_r[1] = mItems[v5 - 1].g;
      p_r[2] = mItems[v5 - 1].b;
      p_r[3] = mItems[v5 - 1].a;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 235
// RVA: 0x156960
void __fastcall UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(
        UFG::PartTemplateInstance::PartEntry *this,
        UFG::PartDefinition::CompositeData *compositeData)
{
  int mNumItems; // esi
  UFG::qReflectArray<float> *p_mSpecularValues; // rbx
  unsigned int v5; // ebp
  __int64 v6; // rdx
  unsigned int v7; // eax
  __int64 v8; // r8
  __int64 v9; // rdx
  __int64 v10; // r8

  mNumItems = compositeData->mSpecularChannelDefaults.mData.mNumItems;
  p_mSpecularValues = &this->mSpecularValues;
  if ( (this->mSpecularValues.mData.mFlags & 2) == 0 )
    operator delete[](p_mSpecularValues->mData.mItems);
  v5 = 0;
  p_mSpecularValues->mData.mItems = 0i64;
  *(_QWORD *)&p_mSpecularValues->mData.mNumItems = 0i64;
  UFG::qReflectArray<float>::Resize(p_mSpecularValues, mNumItems, "qReflectArray.Resize");
  v6 = 0i64;
  if ( mNumItems >= 4 )
  {
    v7 = ((unsigned int)(mNumItems - 4) >> 2) + 1;
    v8 = v7;
    v5 = 4 * v7;
    do
    {
      v6 += 4i64;
      p_mSpecularValues->mData.mItems[v6 - 4] = compositeData->mSpecularChannelDefaults.mData.mItems[v6 - 4];
      p_mSpecularValues->mData.mItems[v6 - 3] = compositeData->mSpecularChannelDefaults.mData.mItems[v6 - 3];
      p_mSpecularValues->mData.mItems[v6 - 2] = compositeData->mSpecularChannelDefaults.mData.mItems[v6 - 2];
      p_mSpecularValues->mData.mItems[v6 - 1] = compositeData->mSpecularChannelDefaults.mData.mItems[v6 - 1];
      --v8;
    }
    while ( v8 );
  }
  if ( v5 < mNumItems )
  {
    v9 = v6;
    v10 = mNumItems - v5;
    do
    {
      ++v9;
      p_mSpecularValues->mData.mItems[v9 - 1] = compositeData->mSpecularChannelDefaults.mData.mItems[v9 - 1];
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 246
// RVA: 0x155610
void __fastcall UFG::PartTemplateInstance::~PartTemplateInstance(UFG::PartTemplateInstance *this)
{
  UFG::PartTextureData *mTextureData; // rbx
  UFG::PartTemplateInstance::SlotEntry *mItems; // rcx
  unsigned int *p_mNumItems; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable;
  mTextureData = this->mTextureData;
  if ( mTextureData )
  {
    UFG::PartTextureData::~PartTextureData(this->mTextureData);
    operator delete[](mTextureData);
    this->mTextureData = 0i64;
  }
  if ( (this->mScalingRegions.mData.mFlags & 2) == 0 )
    operator delete[](this->mScalingRegions.mData.mItems);
  this->mScalingRegions.mData.mItems = 0i64;
  *(_QWORD *)&this->mScalingRegions.mData.mNumItems = 0i64;
  if ( (this->mSlots.mData.mFlags & 2) == 0 )
  {
    mItems = this->mSlots.mData.mItems;
    if ( mItems )
    {
      p_mNumItems = &mItems[-1].mLayers.mData.mNumItems;
      `eh vector destructor iterator(
        mItems,
        0x68ui64,
        mItems[-1].mLayers.mData.mNumItems,
        (void (__fastcall *)(void *))UFG::PartTemplateInstance::SlotEntry::~SlotEntry);
      operator delete[](p_mNumItems);
    }
  }
  this->mSlots.mData.mItems = 0i64;
  *(_QWORD *)&this->mSlots.mData.mNumItems = 0i64;
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mScalingPreset);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mTemplate);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  mPrev = this->mHandles.mNode.mPrev;
  mNext = this->mHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
}

// File Line: 257
// RVA: 0x1562C0
__int64 __fastcall UFG::PartTemplateInstance::AllPartsLoaded(UFG::PartTemplateInstance *this)
{
  unsigned int mNumItems; // eax
  unsigned __int8 v2; // r10
  __int64 v3; // r9
  UFG::qReflectObject **p_mData; // r8
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mNext; // rax

  mNumItems = this->mSlots.mData.mNumItems;
  v2 = 1;
  if ( mNumItems )
  {
    v3 = mNumItems;
    p_mData = &this->mSlots.mData.mItems->mBasePart.mPart.mData;
    do
    {
      if ( *p_mData )
      {
        mNext = UFG::PartDatabase::sInstance->mPool.mRequestList.mNode.mNext;
        if ( mNext == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&UFG::PartDatabase::sInstance->mPool.mRequestList )
          goto LABEL_9;
        while ( mNext[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)(*p_mData)->mBaseNode.mUID )
        {
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&UFG::PartDatabase::sInstance->mPool.mRequestList )
            goto LABEL_9;
        }
        if ( LODWORD(mNext[5].mPrev) != 3 )
LABEL_9:
          v2 = 0;
      }
      p_mData += 13;
      --v3;
    }
    while ( v3 );
  }
  return v2;
}

