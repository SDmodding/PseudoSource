// File Line: 14
// RVA: 0x1466C50
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PartDefinition_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::PartDefinition",
    v0);
  UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PartDefinition>::`vftable';
  UFG::qReflectInventory<UFG::PartDefinition>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PartDefinition,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PartDefinition_UFG::qReflectObject_::sInventory__);
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
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::ScalingPreset",
    v0);
  UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::ScalingPreset>::`vftable';
  UFG::qReflectInventory<UFG::ScalingPreset>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::ScalingPreset,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::ScalingPreset_UFG::qReflectObject_::sInventory__);
}

// File Line: 17
// RVA: 0x159050
const char *__fastcall UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<UFG::PartTemplateInstance,UFG::qReflectObject> *this)
{
  return "UFG::PartTemplateInstance";
}

// File Line: 50
// RVA: 0x158BC0
UFG::qString *__fastcall UFG::PartDefinition::GetModelFileName(UFG::PartDefinition *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  const char *v3; // rax

  v2 = result;
  v3 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&this->vfptr);
  UFG::qString::FormatEx(v2, "Data\\Parts\\%s.bin", v3);
  return v2;
}

// File Line: 55
// RVA: 0x1590A0
UFG::qString *__fastcall UFG::PartDefinition::GetTextureFileName(UFG::PartDefinition *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx
  UFG::PartDefinition *v3; // rdi
  const char *v4; // rax
  const char *v5; // rdx
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-78h]

  v2 = result;
  v3 = this;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  UFG::qString::qString(v2);
  if ( outSettings.mTextureDetailLevel )
  {
    if ( outSettings.mTextureDetailLevel == 1 )
    {
      v4 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v3->vfptr);
      v5 = "Data\\Parts\\SD\\%s.perm.bin";
    }
    else if ( outSettings.mTextureDetailLevel == 2 )
    {
      v4 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v3->vfptr);
      v5 = "Data\\Parts\\HD\\%s.perm.bin";
    }
    else
    {
      v4 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v3->vfptr);
      v5 = "Data\\Parts\\%s.perm.bin";
    }
  }
  else
  {
    v4 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v3->vfptr);
    v5 = "Data\\Parts\\LD\\%s.perm.bin";
  }
  UFG::qString::Format(v2, v5, v4);
  return v2;
}

// File Line: 81
// RVA: 0x158C10
__int64 __fastcall UFG::PartDefinition::GetModelSize(UFG::PartDefinition *this)
{
  UFG::PartDefinition *v1; // rbx
  UFG::qString v3; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  v1 = this;
  if ( this->mModelSize )
    return this->mModelSize;
  UFG::PartDefinition::GetModelFileName(this, &result);
  v1->mModelSize = PartDatabase_QueryFileSize(result.mData);
  UFG::PartDefinition::GetTextureFileName(v1, &v3);
  v1->mModelSize += PartDatabase_QueryFileSize(v3.mData);
  UFG::qString::~qString(&v3);
  UFG::qString::~qString(&result);
  return v1->mModelSize;
}

// File Line: 108
// RVA: 0x159060
UFG::PartDefinition::TextureAlternate *__fastcall UFG::PartDefinition::GetTextureAlternate(UFG::PartDefinition *this, UFG::qSymbolUC *textureSet)
{
  unsigned int v2; // er9
  unsigned int v3; // er8
  unsigned int v4; // edx
  UFG::PartDefinition::TextureAlternate *result; // rax

  v2 = textureSet->mUID;
  if ( textureSet->mUID == UFG::gNullQSymbolUC.mUID )
    return 0i64;
  v3 = this->mTextureAlternates.mData.mNumItems;
  v4 = 0;
  if ( !v3 )
    return 0i64;
  result = this->mTextureAlternates.mData.mItems;
  while ( result->mId.mUID != v2 )
  {
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return 0i64;
  }
  return result;
}

// File Line: 136
// RVA: 0x158CA0
char *__fastcall UFG::PartTemplate::GetNameFromSlotIDRecursive(UFG::PartTemplate *this, UFG::qSymbolUC *slotId, UFG::PartTemplate::Slot *slot)
{
  UFG::PartTemplate::Slot *v3; // rdi
  UFG::qSymbolUC *v4; // rsi
  UFG::PartTemplate *v5; // rbp
  char *result; // rax
  int v7; // ebx

  v3 = slot;
  v4 = slotId;
  v5 = this;
  if ( slot->mSlotName.mUID == slotId->mUID )
  {
    if ( slot->mName.mText.mData.mNumItems )
      result = slot->mName.mText.mData.mItems;
    else
      result = &customWorldMapCaption;
  }
  else
  {
    v7 = 0;
    if ( slot->mChildren.mData.mNumItems )
    {
      while ( 1 )
      {
        result = (char *)UFG::PartTemplate::GetNameFromSlotIDRecursive(v5, v4, &v3->mChildren.mData.mItems[v7]);
        if ( result )
          break;
        if ( ++v7 >= v3->mChildren.mData.mNumItems )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      result = 0i64;
    }
  }
  return result;
}

// File Line: 159
// RVA: 0x158B00
UFG::qReflectObject *__fastcall UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(UFG::PartTemplate *this, UFG::qSymbolUC *slotId, UFG::PartTemplate::Slot *slot)
{
  UFG::PartTemplate::Slot *v3; // rdi
  UFG::qSymbolUC *v4; // rsi
  UFG::PartTemplate *v5; // rbp
  UFG::qReflectObject *result; // rax
  int v7; // ebx

  v3 = slot;
  v4 = slotId;
  v5 = this;
  if ( slot->mSlotName.mUID == slotId->mUID )
    return slot->mCameraSettings.mData;
  v7 = 0;
  if ( !slot->mChildren.mData.mNumItems )
    return 0i64;
  while ( 1 )
  {
    result = UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(v5, v4, &v3->mChildren.mData.mItems[v7]);
    if ( result )
      break;
    if ( ++v7 >= v3->mChildren.mData.mNumItems )
      return 0i64;
  }
  return result;
}

// File Line: 183
// RVA: 0x158FC0
UFG::ScalingPreset::RegionValues *__fastcall UFG::ScalingPreset::GetScaleValues(UFG::ScalingPreset *this, const char *region)
{
  int v2; // edi
  const char *v3; // rbp
  UFG::ScalingPreset *v4; // rsi
  signed __int64 v5; // rbx
  const char *v6; // rdx

  v2 = 0;
  v3 = region;
  v4 = this;
  if ( !this->mRegions.mData.mNumItems )
    return 0i64;
  while ( 1 )
  {
    v5 = (signed __int64)&v4->mRegions.mData.mItems[v2];
    v6 = (const char *)(*(_DWORD *)(v5 + 8) ? *(_QWORD *)v5 : &customWorldMapCaption);
    if ( !(unsigned int)UFG::qStringCompare(v3, v6, -1) )
      break;
    if ( ++v2 >= v4->mRegions.mData.mNumItems )
      return 0i64;
  }
  return (UFG::ScalingPreset::RegionValues *)v5;
}

// File Line: 203
// RVA: 0x1594E0
char __fastcall UFG::PartTemplateInstance::SlotEntry::IsComposited(UFG::PartTemplateInstance::SlotEntry *this)
{
  char result; // al
  __int64 v2; // rdx
  UFG::qReflectObject **v3; // rcx
  bool v4; // zf

  result = 0;
  if ( this->mBasePart.mPart.mData )
  {
    v2 = this->mLayers.mData.mNumItems;
    if ( (_DWORD)v2 )
    {
      v3 = &this->mLayers.mData.mItems->mPart.mData;
      do
      {
        v4 = *v3 == 0i64;
        v3 += 10;
        if ( !v4 )
          result = 1;
        --v2;
      }
      while ( v2 );
    }
  }
  return result;
}

// File Line: 224
// RVA: 0x1568C0
void __fastcall UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(UFG::PartTemplateInstance::PartEntry *this, UFG::PartDefinition::CompositeData *compositeData)
{
  __int64 v2; // rsi
  UFG::qReflectArray<UFG::qColour> *v3; // rdi
  UFG::PartDefinition::CompositeData *v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // r8
  UFG::qColour *v7; // rcx
  float v8; // eax
  float *v9; // rdx

  v2 = compositeData->mDiffuseChannelDefaults.mData.mNumItems;
  v3 = &this->mDiffuseColours;
  v4 = compositeData;
  if ( !(this->mDiffuseColours.mData.mFlags & 2) )
    operator delete[](v3->mData.mItems);
  v5 = 0i64;
  v3->mData.mItems = 0i64;
  *(_QWORD *)&v3->mData.mNumItems = 0i64;
  UFG::qReflectArray<UFG::qColour>::Resize(v3, v2, "qReflectArray.Resize");
  if ( (_DWORD)v2 )
  {
    v6 = v2;
    do
    {
      v7 = v4->mDiffuseChannelDefaults.mData.mItems;
      v8 = v7[v5].r;
      v9 = &v3->mData.mItems[v5].r;
      ++v5;
      *v9 = v8;
      v9[1] = *((float *)&v7[v5] - 3);
      v9[2] = *((float *)&v7[v5] - 2);
      v9[3] = *((float *)&v7[v5] - 1);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 235
// RVA: 0x156960
void __fastcall UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(UFG::PartTemplateInstance::PartEntry *this, UFG::PartDefinition::CompositeData *compositeData)
{
  signed int v2; // esi
  UFG::qReflectArray<float> *v3; // rbx
  UFG::PartDefinition::CompositeData *v4; // rdi
  unsigned int v5; // ebp
  signed __int64 v6; // rdx
  unsigned int v7; // eax
  __int64 v8; // r8
  signed __int64 v9; // rdx
  __int64 v10; // r8

  v2 = compositeData->mSpecularChannelDefaults.mData.mNumItems;
  v3 = &this->mSpecularValues;
  v4 = compositeData;
  if ( !(this->mSpecularValues.mData.mFlags & 2) )
    operator delete[](v3->mData.mItems);
  v5 = 0;
  v3->mData.mItems = 0i64;
  *(_QWORD *)&v3->mData.mNumItems = 0i64;
  UFG::qReflectArray<float>::Resize(v3, v2, "qReflectArray.Resize");
  v6 = 0i64;
  if ( v2 >= 4 )
  {
    v7 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v8 = v7;
    v5 = 4 * v7;
    do
    {
      v6 += 4i64;
      v3->mData.mItems[v6 - 4] = v4->mSpecularChannelDefaults.mData.mItems[v6 - 4];
      v3->mData.mItems[v6 - 3] = v4->mSpecularChannelDefaults.mData.mItems[v6 - 3];
      v3->mData.mItems[v6 - 2] = v4->mSpecularChannelDefaults.mData.mItems[v6 - 2];
      v3->mData.mItems[v6 - 1] = v4->mSpecularChannelDefaults.mData.mItems[v6 - 1];
      --v8;
    }
    while ( v8 );
  }
  if ( v5 < v2 )
  {
    v9 = v6;
    v10 = v2 - v5;
    do
    {
      ++v9;
      v3->mData.mItems[v9 - 1] = v4->mSpecularChannelDefaults.mData.mItems[v9 - 1];
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 246
// RVA: 0x155610
void __fastcall UFG::PartTemplateInstance::~PartTemplateInstance(UFG::PartTemplateInstance *this)
{
  UFG::PartTemplateInstance *v1; // rdi
  UFG::PartTextureData *v2; // rbx
  UFG::PartTemplateInstance::SlotEntry *v3; // rcx
  unsigned int *v4; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v5; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartTemplateInstance::`vftable';
  v2 = this->mTextureData;
  if ( v2 )
  {
    UFG::PartTextureData::~PartTextureData(this->mTextureData);
    operator delete[](v2);
    v1->mTextureData = 0i64;
  }
  if ( !(v1->mScalingRegions.mData.mFlags & 2) )
    operator delete[](v1->mScalingRegions.mData.mItems);
  v1->mScalingRegions.mData.mItems = 0i64;
  *(_QWORD *)&v1->mScalingRegions.mData.mNumItems = 0i64;
  if ( !(v1->mSlots.mData.mFlags & 2) )
  {
    v3 = v1->mSlots.mData.mItems;
    if ( v3 )
    {
      v4 = &v3[-1].mLayers.mData.mNumItems;
      `eh vector destructor iterator'(
        v3,
        0x68ui64,
        v3[-1].mLayers.mData.mNumItems,
        (void (__fastcall *)(void *))UFG::PartTemplateInstance::SlotEntry::~SlotEntry);
      operator delete[](v4);
    }
  }
  v1->mSlots.mData.mItems = 0i64;
  *(_QWORD *)&v1->mSlots.mData.mNumItems = 0i64;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mScalingPreset.mPrev);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mTemplate.mPrev);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&v1->mHandles);
  v5 = v1->mHandles.mNode.mPrev;
  v6 = v1->mHandles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mHandles.mNode.mPrev = &v1->mHandles.mNode;
  v1->mHandles.mNode.mNext = &v1->mHandles.mNode;
}

// File Line: 257
// RVA: 0x1562C0
__int64 __fastcall UFG::PartTemplateInstance::AllPartsLoaded(UFG::PartTemplateInstance *this)
{
  unsigned int v1; // eax
  unsigned __int8 v2; // r10
  __int64 v3; // r9
  UFG::qReflectObject **v4; // r8
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v5; // rax

  v1 = this->mSlots.mData.mNumItems;
  v2 = 1;
  if ( v1 )
  {
    v3 = v1;
    v4 = &this->mSlots.mData.mItems->mBasePart.mPart.mData;
    do
    {
      if ( *v4 )
      {
        v5 = UFG::PartDatabase::sInstance->mPool.mRequestList.mNode.mNext;
        if ( v5 == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&UFG::PartDatabase::sInstance->mPool.mRequestList )
          goto LABEL_9;
        while ( v5[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)(*v4)->mBaseNode.mUID )
        {
          v5 = v5->mNext;
          if ( v5 == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&UFG::PartDatabase::sInstance->mPool.mRequestList )
            goto LABEL_9;
        }
        if ( LODWORD(v5[5].mPrev) != 3 )
LABEL_9:
          v2 = 0;
      }
      v4 += 13;
      --v3;
    }
    while ( v3 );
  }
  return v2;
}

