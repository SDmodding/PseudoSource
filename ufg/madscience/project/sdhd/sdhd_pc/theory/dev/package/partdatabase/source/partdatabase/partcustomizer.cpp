// File Line: 11
// RVA: 0x1466BD0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PartCustomizer_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PartCustomizer", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory,
    "UFG::PartCustomizer",
    v0);
  UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PartCustomizer>::`vftable;
  UFG::qReflectInventory<UFG::PartCustomizer>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PartCustomizer_UFG::DUIWindow_::sInventory__);
}

// File Line: 31
// RVA: 0x159A90
void __fastcall UFG::PartCustomizer::OnPropertyChanged(
        char *object,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        char *field_data,
        _BYTE *user_data)
{
  user_data[420] = 1;
}

// File Line: 70
// RVA: 0x154000
void __fastcall UFG::PartCustomizer::PartCustomizer(UFG::PartCustomizer *this)
{
  unsigned __int64 v2; // rax

  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::PartCustomizer", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &this->mNotification,
    v2,
    UFG::PartCustomizer::OnPropertyChanged,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  this->mSelectedParts.mNode.mPrev = &this->mSelectedParts.mNode;
  this->mSelectedParts.mNode.mNext = &this->mSelectedParts.mNode;
  *(_QWORD *)&this->mCurrentPartTemplate = 0i64;
  this->mCurrentPartEditIndex = 0;
  *(_DWORD *)&this->mCollapseTemplate = 16843009;
  *(_DWORD *)&this->mCollapseDiffuseChannels = 257;
  this->mCompositeDirty = 0;
  UFG::PartLoader::PartLoader(&this->mPartLoader);
  this->mSimObject = 0i64;
  this->mInstance = 0i64;
  UFG::qString::Set(&this->mTitle, "PartCustomizer");
  this->mScrollPos = 0i64;
  *(_QWORD *)&this->mRect.mX = 730i64;
  this->mRect.mW = 550;
  this->mRect.mH = 720;
  this->mNotification.mUserData = this;
  UFG::PartCustomizer::sInstance = this;
}

// File Line: 83
// RVA: 0x1550B0
void __fastcall UFG::PartCustomizer::~PartCustomizer(UFG::PartCustomizer *this)
{
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *mPrev; // rcx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *mNext; // rax

  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::PartCustomizer::sCustomizeComplete(this->mSimObject, this->mInstance);
  UFG::PartCustomizer::sSetCameraOperation(this->mSimObject, 0i64);
  UFG::PartCustomizer::sInstance = 0i64;
  UFG::PartLoader::Unload(&this->mPartLoader);
  `eh vector destructor iterator(this->mPartLoader.mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))_);
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0>::DeleteNodes(&this->mSelectedParts);
  mPrev = this->mSelectedParts.mNode.mPrev;
  mNext = this->mSelectedParts.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mSelectedParts.mNode.mPrev = &this->mSelectedParts.mNode;
  this->mSelectedParts.mNode.mNext = &this->mSelectedParts.mNode;
  UFG::EditNotification::~EditNotification(&this->mNotification);
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 121
// RVA: 0x15AD60
void __fastcall UFG::PartCustomizer::SetupFromTemplate(UFG::PartCustomizer *this)
{
  unsigned int v2; // r14d
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *p_mSelectedParts; // rcx
  UFG::PartTemplateInstance *mInstance; // rbx
  UFG::PartTemplateInstance *v5; // rbx
  UFG::PartTemplate::ScalingRegion *mItems; // rdi

  v2 = 0;
  p_mSelectedParts = &this->mSelectedParts;
  HIDWORD(p_mSelectedParts[1].mNode.mNext) = 0;
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0>::DeleteNodes(p_mSelectedParts);
  UFG::PartCustomizer::AssignSlotDataRecursive(this, &this->mPartTemplate->mSlotTree);
  mInstance = this->mInstance;
  if ( mInstance->mScalingRegions.mData.mNumItems != this->mPartTemplate->mScalingRegions.mData.mNumItems )
  {
    if ( (mInstance->mScalingRegions.mData.mFlags & 2) == 0 )
      operator delete[](mInstance->mScalingRegions.mData.mItems);
    mInstance->mScalingRegions.mData.mItems = 0i64;
    *(_QWORD *)&mInstance->mScalingRegions.mData.mNumItems = 0i64;
    if ( this->mPartTemplate->mScalingRegions.mData.mNumItems )
    {
      do
      {
        v5 = this->mInstance;
        mItems = this->mPartTemplate->mScalingRegions.mData.mItems;
        UFG::qReflectArray<float>::Resize(
          &v5->mScalingRegions,
          v5->mScalingRegions.mData.mNumItems + 1,
          "qReflectArray.Add");
        v5->mScalingRegions.mData.mItems[v5->mScalingRegions.mData.mNumItems - 1] = mItems[v2++].mDefaultScale;
      }
      while ( v2 < this->mPartTemplate->mScalingRegions.mData.mNumItems );
    }
  }
}

// File Line: 170
// RVA: 0x156A50
void __fastcall UFG::PartCustomizer::AssignSlotDataRecursive(UFG::PartCustomizer *this, UFG::PartTemplate::Slot *slot)
{
  UFG::PartTemplate::Slot *v2; // rbx
  unsigned int v3; // edi
  int v4; // r8d
  UFG::PartCustomizer *i; // rax
  char *v6; // rax
  char *v7; // rcx
  unsigned __int64 v8; // rax
  unsigned int v9; // esi
  unsigned int v10; // r9d
  char *v11; // r8
  unsigned int v12; // edx
  UFG::PartTemplate::Slot *v13; // r10
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  char *v18; // rax
  _QWORD *v19; // rdx
  __int64 v20; // r8
  UFG::PartTemplateInstance *mInstance; // rax
  __int64 mCurrentPartDepth; // rcx
  __int64 v23; // rcx
  int v24; // edx
  __int64 v25; // r9
  unsigned int v26; // eax
  unsigned int v27; // r8d
  unsigned int v28; // r10d
  char *v29; // r10
  int v30; // eax
  unsigned int *v31; // r9
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int v34; // ebx
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // ebx
  __int64 j; // rcx
  __int64 v40; // r11
  __int64 v41; // rdx
  int v42; // eax
  __int64 v43; // r9
  unsigned int v44; // ecx
  unsigned int v45; // r8d
  unsigned int v46; // r10d
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v47; // rcx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *mPrev; // rax
  char *mem; // [rsp+28h] [rbp-21h]
  char *v50; // [rsp+30h] [rbp-19h]
  __int64 v51; // [rsp+38h] [rbp-11h]
  unsigned int v52; // [rsp+40h] [rbp-9h]
  UFG::qArray<UFG::PartDefinition *,0> v53; // [rsp+48h] [rbp-1h] BYREF
  UFG::PartDefinition *v54; // [rsp+58h] [rbp+Fh]
  char *v55; // [rsp+60h] [rbp+17h]
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *p_mSelectedParts; // [rsp+68h] [rbp+1Fh]
  __int64 v57; // [rsp+70h] [rbp+27h]
  UFG::PartCustomizer *v58; // [rsp+B0h] [rbp+67h]
  unsigned int v60; // [rsp+C0h] [rbp+77h]
  unsigned int *v61; // [rsp+C0h] [rbp+77h]
  int v62; // [rsp+C0h] [rbp+77h]
  unsigned int v63; // [rsp+C8h] [rbp+7Fh]

  v58 = this;
  v57 = -2i64;
  v2 = slot;
  p_mSelectedParts = &this->mSelectedParts;
  v3 = 0;
  v4 = 0;
  for ( i = (UFG::PartCustomizer *)this->mSelectedParts.mNode.mNext;
        i != (UFG::PartCustomizer *)&this->mSelectedParts;
        i = (UFG::PartCustomizer *)i->mBaseNode.mUID )
  {
    ++v4;
  }
  if ( v4 == this->mCurrentPartDepth )
  {
    v6 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v7 = v6;
    v50 = v6;
    if ( v6 )
    {
      *(_QWORD *)v6 = v6;
      *((_QWORD *)v6 + 1) = v6;
      v6[16] = 0;
      *((_DWORD *)v6 + 5) = -1;
      *((_QWORD *)v6 + 3) = 0i64;
      *((_QWORD *)v6 + 4) = 0i64;
      *((_QWORD *)v6 + 6) = 0i64;
      *((_QWORD *)v6 + 5) = 0i64;
    }
    else
    {
      v7 = 0i64;
      v50 = 0i64;
    }
    *((_DWORD *)v7 + 5) = v2->mSlotName.mUID;
    v60 = 0;
    v8 = 16i64;
    if ( !is_mul_ok(2ui64, 8ui64) )
      v8 = -1i64;
    mem = UFG::qMalloc(v8, "qArray.Add", 0i64);
    v9 = 1;
    *(_QWORD *)mem = 0i64;
    v53.p = 0i64;
    *(_QWORD *)&v53.size = 0i64;
    UFG::PartCustomizer::sGetAvailableParts(&v53, &v2->mSlotName);
    v10 = 0;
    v63 = 0;
    v11 = mem;
    if ( v53.size )
    {
      v12 = 2;
      v13 = slot;
      do
      {
        v54 = v53.p[v10];
        v14 = v60;
        if ( v54->mBaseNode.mUID == v13->mDefaultPart.mNameUID )
          v14 = v10;
        v60 = v14;
        v52 = v9;
        v15 = v9 + 1;
        if ( v9 + 1 > v12 )
        {
          v16 = 1;
          if ( v12 )
            v16 = 2 * v12;
          for ( ; v16 < v15; v16 *= 2 )
            ;
          if ( v16 <= 2 )
            v16 = 2;
          if ( v16 - v15 > 0x10000 )
            v16 = v9 + 65537;
          if ( v16 != v9 )
          {
            v17 = 8i64 * v16;
            if ( !is_mul_ok(v16, 8ui64) )
              v17 = -1i64;
            v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
            v55 = v18;
            if ( mem )
            {
              if ( v9 )
              {
                v19 = v18;
                v20 = v9;
                do
                {
                  *v19 = *(_QWORD *)((char *)v19 + mem - v18);
                  ++v19;
                  --v20;
                }
                while ( v20 );
              }
              operator delete[](mem);
              v18 = v55;
            }
            v11 = v18;
            mem = v18;
            v12 = v16;
            v15 = v9 + 1;
            v10 = v63;
            v13 = slot;
          }
        }
        v9 = v15;
        *(_QWORD *)&v11[8 * v52] = v54;
        v63 = ++v10;
      }
      while ( v10 < v53.size );
      v3 = 0;
    }
    mInstance = v58->mInstance;
    mCurrentPartDepth = (unsigned int)v58->mCurrentPartDepth;
    if ( (signed int)mInstance->mSlots.mData.mNumItems <= (int)mCurrentPartDepth )
    {
      v29 = v50;
      *((_DWORD *)v50 + 6) = v60;
      *((_DWORD *)v50 + 7) = 0;
      *((_QWORD *)v50 + 4) = *(_QWORD *)&v11[8 * v60];
    }
    else
    {
      v23 = (__int64)&mInstance->mSlots.mData.mItems[mCurrentPartDepth];
      v51 = v23;
      v24 = 0;
      if ( v9 )
      {
        while ( 1 )
        {
          v25 = *(_QWORD *)&v11[8 * v24];
          if ( v25 )
          {
            if ( *(_QWORD *)(v23 + 32) == *(_QWORD *)(v25 + 8) )
              break;
          }
          if ( ++v24 >= v9 )
            goto LABEL_45;
        }
        v26 = 0;
        v27 = 0;
        v28 = *(_DWORD *)(v25 + 192);
        if ( v28 )
        {
          while ( *(_DWORD *)(v23 + 48) != *(_DWORD *)(*(_QWORD *)(v25 + 184) + 80i64 * v27) )
          {
            if ( ++v27 >= v28 )
            {
              v26 = 0;
              goto LABEL_44;
            }
          }
          v26 = v27 + 1;
        }
LABEL_44:
        v29 = v50;
        *((_DWORD *)v50 + 6) = v24;
        *((_DWORD *)v50 + 7) = v26;
        *((_QWORD *)v50 + 4) = v25;
        v58->mLoadStatusChanged = 1;
      }
      else
      {
LABEL_45:
        v29 = v50;
      }
      v30 = *(_DWORD *)(v23 + 96);
      v31 = (unsigned int *)(v29 + 40);
      v61 = (unsigned int *)(v29 + 40);
      v32 = *((_DWORD *)v29 + 10);
      v33 = v30 - v32;
      if ( v33 <= 0 )
      {
        v37 = -v33;
        if ( v37 )
        {
          if ( v37 < v32 )
            *v31 = v32 - v37;
          else
            *v31 = 0;
        }
      }
      else
      {
        v34 = v33 + v32;
        v35 = *((_DWORD *)v29 + 11);
        if ( v34 > v35 )
        {
          v36 = 1;
          if ( v35 )
            v36 = 2 * v35;
          for ( ; v36 < v34; v36 *= 2 )
            ;
          if ( v36 - v34 > 0x10000 )
            v36 = v34 + 0x10000;
          UFG::qArray<UFG::PartCustomizer::PartSelection,0>::Reallocate(
            (UFG::qArray<UFG::PartCustomizer::PartSelection,0> *)(v29 + 40),
            v36,
            "qArray.Reallocate(Resize)");
          v31 = v61;
          v29 = v50;
        }
        *v31 = v34;
      }
      v38 = 0;
      v62 = 0;
      for ( j = v51; v38 < *(_DWORD *)(v51 + 96); j = v51 )
      {
        v40 = *((_QWORD *)v29 + 6) + 16i64 * v38;
        v41 = *(_QWORD *)(j + 88) + 80i64 * v38;
        v42 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v43 = *(_QWORD *)&mem[8 * v42];
            if ( v43 )
            {
              if ( *(_QWORD *)(v41 + 24) == *(_QWORD *)(v43 + 8) )
                break;
            }
            if ( ++v42 >= v9 )
              goto LABEL_73;
          }
          v44 = 0;
          v45 = 0;
          v46 = *(_DWORD *)(v43 + 192);
          if ( v46 )
          {
            while ( *(_DWORD *)(v41 + 40) != *(_DWORD *)(*(_QWORD *)(v43 + 184) + 80i64 * v45) )
            {
              if ( ++v45 >= v46 )
              {
                v44 = 0;
                goto LABEL_71;
              }
            }
            v44 = v45 + 1;
LABEL_71:
            v38 = v62;
          }
          *(_DWORD *)v40 = v42;
          *(_DWORD *)(v40 + 4) = v44;
          *(_QWORD *)(v40 + 8) = v43;
          v58->mLoadStatusChanged = 1;
          v29 = v50;
        }
LABEL_73:
        v62 = ++v38;
      }
    }
    v29[16] = v58->mCurrentPartDepth == 0;
    v47 = p_mSelectedParts;
    mPrev = p_mSelectedParts->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v29;
    *(_QWORD *)v29 = mPrev;
    *((_QWORD *)v29 + 1) = v47;
    v47->mNode.mPrev = (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v29;
    if ( v53.p )
      operator delete[](v53.p);
    v53.p = 0i64;
    *(_QWORD *)&v53.size = 0i64;
    if ( mem )
      operator delete[](mem);
    this = v58;
    v2 = slot;
  }
  ++this->mCurrentPartDepth;
  if ( v2->mChildren.mData.mNumItems )
  {
    do
    {
      UFG::PartCustomizer::AssignSlotDataRecursive(this, &v2->mChildren.mData.mItems[v3++]);
      this = v58;
    }
    while ( v3 < v2->mChildren.mData.mNumItems );
  }
}

// File Line: 232
// RVA: 0x159B60
void __fastcall UFG::PartCustomizer::PopulateSelectionUI(
        UFG::PartCustomizer *this,
        UFG::DUIContext *dui,
        UFG::PartCustomizer::PartSelection *selection,
        UFG::qList<UFG::qString,UFG::qString,1,0> *partNames,
        UFG::qArray<UFG::PartDefinition *,0> *parts)
{
  bool v9; // al
  UFG::qArray<UFG::PartDefinition *,0> *v10; // rdx
  UFG::PartDefinition *v11; // rbx
  char *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  __int64 i; // rdi
  char *v17; // rax
  __int64 v18; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  int v22; // ecx
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+40h] [rbp-10h] BYREF
  int current_index; // [rsp+80h] [rbp+30h] BYREF

  UFG::DUIContext::BeginIndent(dui);
  current_index = selection->mPartSelectionIndex;
  v9 = UFG::DUIContext::ComboBox(dui, &current_index, partNames, 0i64, 0xFFFFFFFF);
  v10 = parts;
  if ( v9 && current_index >= 0 && current_index < (signed int)parts->size )
  {
    selection->mPartSelectionIndex = current_index;
    selection->mTextureSetSelectionIndex = 0;
    this->mCurrentPartEditIndex = this->mCurrentPartDepth + 1;
    this->mLoadStatusChanged = 1;
  }
  if ( (signed int)v10->size <= selection->mPartSelectionIndex )
    v11 = 0i64;
  else
    v11 = v10->p[selection->mPartSelectionIndex];
  selection->mPart = v11;
  if ( v11 && v11->mTextureAlternates.mData.mNumItems )
  {
    UFG::DUIContext::Label(dui, "Select Texture Set");
    options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    v12 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    if ( v12 )
    {
      UFG::qString::qString((UFG::qString *)v12, "Default");
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    mPrev = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v14;
    v14->mPrev = mPrev;
    v14->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v14;
    for ( i = 0i64; (unsigned int)i < v11->mTextureAlternates.mData.mNumItems; i = (unsigned int)(i + 1) )
    {
      v17 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v17 )
      {
        v18 = (__int64)&v11->mTextureAlternates.mData.mItems[i];
        if ( *(_DWORD *)(v18 + 16) )
          UFG::qString::qString((UFG::qString *)v17, *(const char **)(v18 + 8));
        else
          UFG::qString::qString((UFG::qString *)v17, &customCaption);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      v21 = options.mNode.mPrev;
      options.mNode.mPrev->mNext = v20;
      v20->mPrev = v21;
      v20->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
      options.mNode.mPrev = v20;
    }
    LODWORD(parts) = selection->mTextureSetSelectionIndex;
    if ( UFG::DUIContext::ComboBox(dui, (int *)&parts, &options, 0i64, 0xFFFFFFFF) )
    {
      v22 = (int)parts;
      if ( (int)parts >= 0 )
      {
        this->mCurrentPartEditIndex = this->mCurrentPartDepth + 1;
        selection->mTextureSetSelectionIndex = v22;
        this->mLoadStatusChanged = 1;
      }
    }
    for ( j = (UFG::qString *)options.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
          j = (UFG::qString *)options.mNode.mNext )
    {
      v24 = j->mPrev;
      mNext = j->mNext;
      v24->mNext = mNext;
      mNext->mPrev = v24;
      j->mPrev = j;
      j->mNext = j;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    v26 = options.mNode.mPrev;
    v27 = options.mNode.mNext;
    options.mNode.mPrev->mNext = options.mNode.mNext;
    v27->mPrev = v26;
    options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  }
  UFG::DUIContext::EndIndent(dui);
}

// File Line: 282
// RVA: 0x157CE0
void __fastcall UFG::PartCustomizer::BuildSlotTree(
        UFG::PartCustomizer *this,
        UFG::DUIContext *dui,
        UFG::PartTemplate::Slot *slot,
        bool parent_expanded)
{
  char *mItems; // r8
  int mCurrentPartDepth; // eax
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *mNext; // rsi
  unsigned int v10; // edi
  char *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  unsigned __int64 v15; // rax
  int v16; // ebx
  unsigned int v17; // eax
  char *v18; // rsi
  const char *Name; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned __int64 v25; // rax
  char *v26; // rcx
  UFG::PartDefinition **p; // r10
  _QWORD *v28; // rdx
  char *v29; // r9
  __int64 size; // r8
  UFG::qArray<UFG::PartCustomizer::PartSelection,0> *p_mNext; // rbx
  unsigned int v32; // esi
  __int64 v33; // rdi
  UFG::DUIContext *v34; // rsi
  unsigned int v35; // esi
  unsigned int capacity; // ecx
  unsigned int v37; // ecx
  UFG::PartCustomizer::PartSelection *v38; // rcx
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  bool v44; // cl
  UFG::PartCustomizer *v45; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> partNames; // [rsp+30h] [rbp-59h] BYREF
  UFG::qArray<UFG::PartDefinition *,0> parts; // [rsp+40h] [rbp-49h] BYREF
  unsigned int v48; // [rsp+50h] [rbp-39h]
  UFG::qArray<UFG::PartDefinition *,0> v49; // [rsp+58h] [rbp-31h] BYREF
  char *v50; // [rsp+68h] [rbp-21h]
  int v51; // [rsp+70h] [rbp-19h]
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v52; // [rsp+78h] [rbp-11h]
  UFG::qReflectObject *v53; // [rsp+80h] [rbp-9h]
  __int64 v54; // [rsp+88h] [rbp-1h]
  UFG::qString result; // [rsp+90h] [rbp+7h] BYREF
  char v59; // [rsp+108h] [rbp+7Fh]

  v54 = -2i64;
  UFG::DUIContext::BeginIndent(dui);
  if ( slot->mName.mText.mData.mNumItems )
    mItems = slot->mName.mText.mData.mItems;
  else
    mItems = &customCaption;
  UFG::qString::FormatEx(&result, "Slot: %s", mItems);
  mCurrentPartDepth = this->mCurrentPartDepth;
  mNext = this->mSelectedParts.mNode.mNext;
  v52 = mNext;
  if ( mCurrentPartDepth > 0 )
  {
    do
    {
      if ( mNext == (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)&this->mSelectedParts )
        break;
      --mCurrentPartDepth;
      mNext = mNext->mNext;
    }
    while ( mCurrentPartDepth > 0 );
    v52 = mNext;
  }
  v10 = 0;
  if ( parent_expanded && UFG::DUIContext::Collapsible(dui, result.mData, (bool *)&mNext[1]) )
  {
    v59 = 1;
    partNames.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    parts.p = 0i64;
    *(_QWORD *)&parts.size = 0i64;
    v11 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v50 = v11;
    if ( v11 )
    {
      UFG::qString::qString((UFG::qString *)v11, "Empty");
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    mPrev = partNames.mNode.mPrev;
    partNames.mNode.mPrev->mNext = v13;
    v13->mPrev = mPrev;
    v13->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mPrev = v13;
    v15 = 16i64;
    if ( !is_mul_ok(2ui64, 8ui64) )
      v15 = -1i64;
    parts.p = (UFG::PartDefinition **)UFG::qMalloc(v15, "qArray.Add", 0i64);
    parts.capacity = 2;
    v16 = 1;
    parts.size = 1;
    *parts.p = 0i64;
    v49.p = 0i64;
    *(_QWORD *)&v49.size = 0i64;
    UFG::PartCustomizer::sGetAvailableParts(&v49, &slot->mSlotName);
    v17 = 0;
    v48 = 0;
    if ( v49.size )
    {
      do
      {
        v53 = v49.p[v17];
        v18 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v50 = v18;
        if ( v18 )
        {
          Name = UFG::qReflectObject::GetName(v53);
          UFG::qString::qString((UFG::qString *)v18, Name);
          v21 = v20;
        }
        else
        {
          v21 = 0i64;
        }
        v22 = partNames.mNode.mPrev;
        partNames.mNode.mPrev->mNext = v21;
        v21->mPrev = v22;
        v21->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
        partNames.mNode.mPrev = v21;
        v51 = v16;
        v23 = v16 + 1;
        if ( v16 + 1 > parts.capacity )
        {
          v24 = 1;
          if ( parts.capacity )
            v24 = 2 * parts.capacity;
          for ( ; v24 < v23; v24 *= 2 )
            ;
          if ( v24 <= 2 )
            v24 = 2;
          if ( v24 - v23 > 0x10000 )
            v24 = v23 + 0x10000;
          if ( v24 != parts.size )
          {
            v25 = 8i64 * v24;
            if ( !is_mul_ok(v24, 8ui64) )
              v25 = -1i64;
            v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
            v50 = v26;
            p = parts.p;
            if ( parts.p )
            {
              if ( parts.size )
              {
                v28 = v26;
                v29 = (char *)((char *)parts.p - v26);
                size = parts.size;
                do
                {
                  *v28 = *(_QWORD *)((char *)v28 + (_QWORD)v29);
                  ++v28;
                  --size;
                }
                while ( size );
              }
              operator delete[](p);
              v26 = v50;
            }
            parts.p = (UFG::PartDefinition **)v26;
            parts.capacity = v24;
          }
        }
        v16 = v23;
        parts.size = v23;
        parts.p[v51] = (UFG::PartDefinition *)v53;
        v17 = v48 + 1;
        v48 = v17;
      }
      while ( v17 < v49.size );
      mNext = v52;
    }
    UFG::PartCustomizer::PopulateSelectionUI(
      this,
      dui,
      (UFG::PartCustomizer::PartSelection *)&mNext[1].mNext,
      &partNames,
      &parts);
    UFG::DUIContext::BeginIndent(dui);
    p_mNext = (UFG::qArray<UFG::PartCustomizer::PartSelection,0> *)&mNext[2].mNext;
    if ( LODWORD(mNext[2].mNext) )
    {
      UFG::DUIContext::Label(dui, "Layers:");
      v32 = 0;
      if ( p_mNext->size )
      {
        v33 = (__int64)v52;
        do
          UFG::PartCustomizer::PopulateSelectionUI(
            this,
            dui,
            (UFG::PartCustomizer::PartSelection *)(*(_QWORD *)(v33 + 48) + 16i64 * v32++),
            &partNames,
            &parts);
        while ( v32 < p_mNext->size );
        v10 = 0;
      }
    }
    v34 = dui;
    if ( UFG::DUIContext::Button(dui, "Add Layer", 0x10u) )
    {
      v35 = p_mNext->size + 1;
      capacity = p_mNext->capacity;
      if ( v35 > capacity )
      {
        if ( capacity )
          v37 = 2 * capacity;
        else
          v37 = 1;
        for ( ; v37 < v35; v37 *= 2 )
          ;
        if ( v37 - v35 > 0x10000 )
          v37 = p_mNext->size + 65537;
        UFG::qArray<UFG::PartCustomizer::PartSelection,0>::Reallocate(p_mNext, v37, "qArray.Add");
      }
      p_mNext->size = v35;
      v34 = dui;
    }
    if ( UFG::DUIContext::Button(v34, "Delete Layers", 0x10u) )
    {
      v38 = p_mNext->p;
      if ( v38 )
        operator delete[](v38);
      p_mNext->p = 0i64;
      *(_QWORD *)&p_mNext->size = 0i64;
      this->mLoadStatusChanged = 1;
    }
    UFG::DUIContext::EndIndent(v34);
    if ( v49.p )
      operator delete[](v49.p);
    v49.p = 0i64;
    *(_QWORD *)&v49.size = 0i64;
    if ( parts.p )
      operator delete[](parts.p);
    parts.p = 0i64;
    *(_QWORD *)&parts.size = 0i64;
    for ( i = (UFG::qString *)partNames.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)partNames.mNode.mNext != &partNames;
          i = (UFG::qString *)partNames.mNode.mNext )
    {
      v40 = i->mPrev;
      v41 = i->mNext;
      v40->mNext = v41;
      v41->mPrev = v40;
      i->mPrev = i;
      i->mNext = i;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    v42 = partNames.mNode.mPrev;
    v43 = partNames.mNode.mNext;
    partNames.mNode.mPrev->mNext = partNames.mNode.mNext;
    v43->mPrev = v42;
    partNames.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    v44 = 1;
  }
  else
  {
    v44 = 0;
    v59 = 0;
    v34 = dui;
  }
  v45 = this;
  ++this->mCurrentPartDepth;
  if ( slot->mChildren.mData.mNumItems )
  {
    do
    {
      UFG::PartCustomizer::BuildSlotTree(v45, v34, &slot->mChildren.mData.mItems[v10++], v44);
      v45 = this;
      v44 = v59;
    }
    while ( v10 < slot->mChildren.mData.mNumItems );
  }
  UFG::DUIContext::EndIndent(v34);
  UFG::qString::~qString(&result);
}

// File Line: 345
// RVA: 0x157630
void __fastcall UFG::PartCustomizer::BuildPartSelectionUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::PartCustomizer *v3; // r12
  _BYTE *v4; // r14
  int v5; // esi
  unsigned int v6; // r15d
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  UFG::qTree64Base *Head; // rax
  UFG::qReflectObject *p_mCount; // r13
  UFG::qTree64Base *v11; // r12
  char *v12; // rbx
  const char *Name; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  unsigned int v17; // ecx
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  char *v21; // rax
  __int64 v22; // r15
  _QWORD *v23; // rdx
  __int64 v24; // r8
  UFG::qTree64Base *Next; // rax
  float mCurrentPartTemplate; // xmm0_4
  bool v27; // zf
  __int64 v28; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+38h] [rbp-30h] BYREF
  __int64 v35; // [rsp+48h] [rbp-20h]
  __int64 v36; // [rsp+50h] [rbp-18h]
  int current_index; // [rsp+C0h] [rbp+58h] BYREF
  UFG::qTree64Base *p_mTree; // [rsp+C8h] [rbp+60h]

  v2 = dui;
  v3 = this;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v4 = 0i64;
  v36 = 0i64;
  v5 = 0;
  v35 = 0i64;
  v6 = 0;
  v7 = UFG::qStringHash64("UFG::PartTemplate", 0xFFFFFFFFFFFFFFFFui64);
  v8 = UFG::qReflectWarehouse::Instance();
  p_mTree = &UFG::qReflectWarehouse::GetInventory(v8, v7)->mItems.mTree;
  Head = UFG::qTree64Base::GetHead(p_mTree);
  if ( Head )
  {
    p_mCount = (UFG::qReflectObject *)&Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      v11 = p_mTree;
      do
      {
        v12 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        p_mTree = (UFG::qTree64Base *)v12;
        if ( v12 )
        {
          Name = UFG::qReflectObject::GetName(p_mCount);
          UFG::qString::qString((UFG::qString *)v12, Name);
          v15 = v14;
        }
        else
        {
          v15 = 0i64;
        }
        mPrev = options.mNode.mPrev;
        options.mNode.mPrev->mNext = v15;
        v15->mPrev = mPrev;
        v15->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        options.mNode.mPrev = v15;
        v17 = v5;
        LODWORD(p_mTree) = v5;
        v18 = v5 + 1;
        if ( v5 + 1 > v6 )
        {
          v19 = 1;
          if ( v6 )
            v19 = 2 * v6;
          for ( ; v19 < v18; v19 *= 2 )
            ;
          if ( v19 <= 2 )
            v19 = 2;
          if ( v19 - v18 > 0x10000 )
            v19 = v5 + 65537;
          if ( v19 != v5 )
          {
            v20 = 8i64 * v19;
            if ( !is_mul_ok(v19, 8ui64) )
              v20 = -1i64;
            v21 = UFG::qMalloc(v20, "qArray.Add", 0i64);
            v22 = (__int64)v21;
            if ( v4 )
            {
              if ( v5 )
              {
                v23 = v21;
                v24 = (unsigned int)v5;
                do
                {
                  *v23 = *(_QWORD *)((char *)v23 + v4 - v21);
                  ++v23;
                  --v24;
                }
                while ( v24 );
              }
              operator delete[](v4);
            }
            v4 = (_BYTE *)v22;
            v36 = v22;
            v6 = v19;
            HIDWORD(v35) = v19;
            v17 = (unsigned int)p_mTree;
          }
        }
        ++v5;
        LODWORD(v35) = v18;
        *(_QWORD *)&v4[8 * v17] = p_mCount;
        Next = UFG::qTree64Base::GetNext(v11, &p_mCount->mBaseNode);
        if ( !Next )
          break;
        p_mCount = (UFG::qReflectObject *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
      v3 = this;
      v2 = dui;
    }
  }
  mCurrentPartTemplate = (float)v3->mCurrentPartTemplate;
  if ( mCurrentPartTemplate >= (float)(v5 - 1) )
    mCurrentPartTemplate = (float)(v5 - 1);
  current_index = (int)mCurrentPartTemplate;
  UFG::DUIContext::Label(v2, "Select a Template");
  v27 = !UFG::DUIContext::ComboBox(v2, &current_index, &options, 0i64, 0xFFFFFFFF);
  v28 = (unsigned int)current_index;
  if ( !v27 && current_index >= 0 )
  {
    v3->mCurrentPartTemplate = current_index;
    v3->mPartTemplate = *(UFG::PartTemplate **)&v4[8 * v28];
    UFG::PartCustomizer::SetupFromTemplate(v3);
    v28 = (unsigned int)current_index;
  }
  if ( v5 > (int)v28 && (int)v28 >= 0 )
    v3->mPartTemplate = *(UFG::PartTemplate **)&v4[8 * v28];
  if ( UFG::DUIContext::Collapsible(v2, "Select Parts", &v3->mCollapsePartSelection) )
  {
    v3->mCurrentPartDepth = 0;
    if ( current_index >= 0 )
      UFG::PartCustomizer::BuildSlotTree(
        v3,
        v2,
        (UFG::PartTemplate::Slot *)(*(_QWORD *)&v4[8 * v3->mCurrentPartTemplate] + 80i64),
        1);
  }
  if ( v4 )
    operator delete[](v4);
  v36 = 0i64;
  v35 = 0i64;
  for ( i = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        i = (UFG::qString *)options.mNode.mNext )
  {
    v30 = i->mPrev;
    mNext = i->mNext;
    v30->mNext = mNext;
    mNext->mPrev = v30;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v32 = options.mNode.mPrev;
  v33 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v33->mPrev = v32;
}

// File Line: 386
// RVA: 0x157AB0
void __fastcall UFG::PartCustomizer::BuildSlotEntryUI(
        UFG::PartCustomizer *this,
        UFG::DUIContext *dui,
        UFG::PartTemplateInstance::PartEntry *part_entry)
{
  UFG::qReflectObject *mData; // rax
  UFG::PartDefinition::CompositeData *p_mHandles; // r15
  unsigned int mUID; // edx
  __int64 v9; // rdi
  unsigned int v10; // ecx
  unsigned int v11; // r8d
  UFG::PartDefinition::CompositeData *v12; // rax
  unsigned int i; // esi
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF

  mData = part_entry->mPart.mData;
  p_mHandles = (UFG::PartDefinition::CompositeData *)&mData[1].mHandles;
  mUID = part_entry->mTextureSet.mUID;
  v9 = 0i64;
  if ( mUID != UFG::gNullQSymbolUC.mUID )
  {
    v10 = (unsigned int)mData[2].mBaseNode.mChildren[1];
    v11 = 0;
    if ( v10 )
    {
      v12 = (UFG::PartDefinition::CompositeData *)mData[2].mBaseNode.mChildren[0];
      while ( LODWORD(v12->mAlpha) != mUID )
      {
        ++v11;
        v12 += 2;
        if ( v11 >= v10 )
          goto LABEL_8;
      }
      p_mHandles = v12 + 1;
    }
  }
LABEL_8:
  UFG::DUIContext::BeginIndent(dui);
  if ( p_mHandles->mDiffuseChannelDefaults.mData.mNumItems )
  {
    if ( UFG::DUIContext::Button(dui, "Reset Diffuse Colours to Defaults", 0x10u) )
    {
      UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(part_entry, p_mHandles);
      this->mCompositeDirty = 1;
    }
    if ( UFG::DUIContext::Collapsible(dui, "Diffuse Colour Channels", &this->mCollapseDiffuseChannels) )
    {
      for ( i = 0; i < part_entry->mDiffuseColours.mData.mNumItems; ++i )
      {
        UFG::qString::FormatEx(&result, "Channel %d", i);
        if ( UFG::DUIContext::ColourPicker(dui, result.mData, &part_entry->mDiffuseColours.mData.mItems[i], 0) )
          this->mCompositeDirty = 1;
        UFG::qString::~qString(&result);
      }
    }
  }
  if ( p_mHandles->mSpecularChannelDefaults.mData.mNumItems )
  {
    if ( UFG::DUIContext::Button(dui, "Reset Specular Colours to Defaults", 0x10u) )
    {
      UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(part_entry, p_mHandles);
      this->mCompositeDirty = 1;
    }
    if ( UFG::DUIContext::Collapsible(dui, "Specular Colour Channels", &this->mCollapseSpecularChannels) )
    {
      UFG::DUIContext::BeginIndent(dui);
      if ( part_entry->mSpecularValues.mData.mNumItems )
      {
        do
        {
          UFG::qString::FormatEx(&result, "Channel %d", (unsigned int)v9);
          if ( UFG::DUIContext::Slider(dui, result.mData, &part_entry->mSpecularValues.mData.mItems[v9], 0.0, 1.0, 0.0) )
            this->mCompositeDirty = 1;
          UFG::qString::~qString(&result);
          v9 = (unsigned int)(v9 + 1);
        }
        while ( (unsigned int)v9 < part_entry->mSpecularValues.mData.mNumItems );
      }
      UFG::DUIContext::EndIndent(dui);
    }
  }
  UFG::DUIContext::EndIndent(dui);
}

// File Line: 445
// RVA: 0x157250
void __fastcall UFG::PartCustomizer::BuildPartEditUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartTemplate *mData; // r13
  _BYTE *v4; // r12
  unsigned int v5; // esi
  unsigned int v6; // r14d
  char *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  unsigned int v11; // ecx
  UFG::PartTemplateInstance::SlotEntry *v12; // r13
  unsigned int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // ebx
  unsigned __int64 v16; // rax
  char *v17; // rax
  __int64 v18; // r14
  _QWORD *v19; // rdx
  __int64 v20; // r8
  char *v21; // rbx
  UFG::qSymbolUC *p_mSlotName; // rdx
  const char *NameFromSlotIDRecursive; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  int v27; // esi
  float mCurrentPartEditIndex; // xmm0_4
  int v29; // eax
  __int64 v30; // rdi
  __int64 j; // rbx
  UFG::PartTemplateInstance::PartEntry *v32; // r8
  UFG::qReflectObject *CameraSettingFromSlotIDRecursive; // rax
  int v34; // ebx
  unsigned int mNumItems; // esi
  UFG::PartTemplate::Slot *mItems; // r14
  UFG::qReflectObject *v37; // rdx
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rax
  UFG::PartTemplate *v43; // [rsp+30h] [rbp-38h]
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+40h] [rbp-28h] BYREF
  __int64 v45; // [rsp+50h] [rbp-18h]
  __int64 v46; // [rsp+58h] [rbp-10h]
  unsigned int i; // [rsp+B0h] [rbp+48h]
  int current_index; // [rsp+C0h] [rbp+58h] BYREF
  char *v50; // [rsp+C8h] [rbp+60h]

  mData = (UFG::PartTemplate *)this->mInstance->mTemplate.mData;
  v43 = mData;
  v4 = 0i64;
  v46 = 0i64;
  v5 = 0;
  v45 = 0i64;
  v6 = 0;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v7 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v7 )
  {
    UFG::qString::qString((UFG::qString *)v7, "Select Part to Edit");
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  mPrev = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v9;
  v9->mPrev = mPrev;
  v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v9;
  v11 = 0;
  for ( i = 0; v11 < this->mInstance->mSlots.mData.mNumItems; i = v11 )
  {
    v12 = &this->mInstance->mSlots.mData.mItems[v11];
    v13 = v5;
    v14 = v5 + 1;
    if ( v5 + 1 > v6 )
    {
      v15 = 1;
      if ( v6 )
        v15 = 2 * v6;
      for ( ; v15 < v14; v15 *= 2 )
        ;
      if ( v15 <= 2 )
        v15 = 2;
      if ( v15 - v14 > 0x10000 )
        v15 = v5 + 65537;
      if ( v15 != v5 )
      {
        v16 = 8i64 * v15;
        if ( !is_mul_ok(v15, 8ui64) )
          v16 = -1i64;
        v17 = UFG::qMalloc(v16, "qArray.Add", 0i64);
        v18 = (__int64)v17;
        if ( v4 )
        {
          if ( v5 )
          {
            v19 = v17;
            v20 = v5;
            do
            {
              *v19 = *(_QWORD *)((char *)v19 + v4 - v17);
              ++v19;
              --v20;
            }
            while ( v20 );
          }
          operator delete[](v4);
        }
        v4 = (_BYTE *)v18;
        v46 = v18;
        v6 = v15;
        HIDWORD(v45) = v15;
        v13 = v5;
      }
    }
    ++v5;
    LODWORD(v45) = v14;
    *(_QWORD *)&v4[8 * v13] = v12;
    v21 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v50 = v21;
    if ( v21 )
    {
      p_mSlotName = &v12->mSlotName;
      mData = v43;
      NameFromSlotIDRecursive = UFG::PartTemplate::GetNameFromSlotIDRecursive(v43, p_mSlotName, &v43->mSlotTree);
      UFG::qString::qString((UFG::qString *)v21, NameFromSlotIDRecursive);
      v25 = v24;
    }
    else
    {
      v25 = 0i64;
      mData = v43;
    }
    v26 = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v25;
    v25->mPrev = v26;
    v25->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v25;
    v11 = i + 1;
  }
  v27 = v5 + 1;
  mCurrentPartEditIndex = (float)this->mCurrentPartEditIndex;
  if ( mCurrentPartEditIndex >= (float)v27 )
    mCurrentPartEditIndex = (float)v27;
  current_index = (int)mCurrentPartEditIndex;
  if ( UFG::DUIContext::ComboBox(dui, &current_index, &options, 0i64, 0xFFFFFFFF) && this->mCurrentPartEditIndex >= 0 )
    this->mCurrentPartEditIndex = current_index;
  if ( v27 < 0 )
    v27 = 0;
  v29 = this->mCurrentPartEditIndex;
  if ( v27 < v29 )
    v29 = v27;
  this->mCurrentPartEditIndex = v29;
  if ( v29 <= 0 )
  {
    v37 = mData->mSlotTree.mCameraSettings.mData;
  }
  else
  {
    v30 = *(_QWORD *)&v4[8 * (v29 - 1)];
    if ( *(_QWORD *)(v30 + 40) )
    {
      UFG::PartCustomizer::BuildSlotEntryUI(this, dui, (UFG::PartTemplateInstance::PartEntry *)(v30 + 8));
      for ( j = 0i64; (unsigned int)j < *(_DWORD *)(v30 + 96); j = (unsigned int)(j + 1) )
      {
        v32 = (UFG::PartTemplateInstance::PartEntry *)(*(_QWORD *)(v30 + 88) + 80 * j);
        if ( v32->mPart.mData )
          UFG::PartCustomizer::BuildSlotEntryUI(this, dui, v32);
      }
    }
    if ( mData->mSlotTree.mSlotName.mUID == *(_DWORD *)v30 )
    {
      CameraSettingFromSlotIDRecursive = mData->mSlotTree.mCameraSettings.mData;
    }
    else
    {
      v34 = 0;
      mNumItems = mData->mSlotTree.mChildren.mData.mNumItems;
      if ( mNumItems )
      {
        mItems = mData->mSlotTree.mChildren.mData.mItems;
        while ( 1 )
        {
          CameraSettingFromSlotIDRecursive = UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(
                                               mData,
                                               (UFG::qSymbolUC *)v30,
                                               &mItems[v34]);
          if ( CameraSettingFromSlotIDRecursive )
            break;
          if ( ++v34 >= mNumItems )
            goto LABEL_49;
        }
      }
      else
      {
LABEL_49:
        CameraSettingFromSlotIDRecursive = 0i64;
      }
    }
    if ( !CameraSettingFromSlotIDRecursive )
      CameraSettingFromSlotIDRecursive = mData->mSlotTree.mCameraSettings.mData;
    v37 = CameraSettingFromSlotIDRecursive;
  }
  UFG::PartCustomizer::sSetCameraOperation(this->mSimObject, v37);
  for ( k = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        k = (UFG::qString *)options.mNode.mNext )
  {
    v39 = k->mPrev;
    mNext = k->mNext;
    v39->mNext = mNext;
    mNext->mPrev = v39;
    k->mPrev = k;
    k->mNext = k;
    UFG::qString::~qString(k);
    operator delete[](k);
  }
  v41 = options.mNode.mPrev;
  v42 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v42->mPrev = v41;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  if ( v4 )
    operator delete[](v4);
}

// File Line: 498
// RVA: 0x157980
void __fastcall UFG::PartCustomizer::BuildScalingUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartTemplateInstance *mInstance; // r8
  UFG::qReflectObject *mData; // rdi
  UFG::PartTemplateInstance *v6; // rbx
  __int64 i; // rbx
  __int64 v8; // r8
  const char *v9; // rdx

  mInstance = this->mInstance;
  mData = mInstance->mTemplate.mData;
  if ( mInstance->mScalingRegions.mData.mNumItems < LODWORD(mData[2].mBaseNode.mNeighbours[1]) )
  {
    do
    {
      v6 = this->mInstance;
      UFG::qReflectArray<float>::Resize(
        &v6->mScalingRegions,
        v6->mScalingRegions.mData.mNumItems + 1,
        "qReflectArray.Add");
      v6->mScalingRegions.mData.mItems[v6->mScalingRegions.mData.mNumItems - 1] = 1.0;
    }
    while ( this->mInstance->mScalingRegions.mData.mNumItems < LODWORD(mData[2].mBaseNode.mNeighbours[1]) );
  }
  for ( i = 0i64; (unsigned int)i < LODWORD(mData[2].mBaseNode.mNeighbours[1]); i = (unsigned int)(i + 1) )
  {
    v8 = (__int64)&mData[2].mBaseNode.mNeighbours[0][i];
    if ( *(_DWORD *)(v8 + 8) )
      v9 = *(const char **)v8;
    else
      v9 = &customCaption;
    if ( UFG::DUIContext::Slider(
           dui,
           v9,
           &this->mInstance->mScalingRegions.mData.mItems[i],
           *(float *)(v8 + 36),
           *(float *)(v8 + 40),
           0.0) )
    {
      this->mScalingDirty = 1;
    }
  }
}

// File Line: 515
// RVA: 0x1581F0
void __fastcall UFG::PartCustomizer::BuildUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartTemplateInstance *mInstance; // rdx
  UFG::CompositeBuild *mProcessingBuild; // rax
  UFG::PartCompositeBuilder *mNext; // rax

  mInstance = this->mInstance;
  mProcessingBuild = UFG::PartCompositeBuilder::sInstance->mProcessingBuild;
  if ( mProcessingBuild && mProcessingBuild->mDefinition == mInstance )
  {
LABEL_15:
    UFG::DUIContext::Label(dui, "Build Pending...");
    return;
  }
  mNext = (UFG::PartCompositeBuilder *)UFG::PartCompositeBuilder::sInstance->mPendingBuilds.mNode.mNext;
  if ( mNext != (UFG::PartCompositeBuilder *)&UFG::PartCompositeBuilder::sInstance->mPendingBuilds )
  {
    while ( (UFG::PartTemplateInstance *)mNext->mPendingBuilds.mNode.mPrev != mInstance )
    {
      mNext = (UFG::PartCompositeBuilder *)mNext->mFreeTargets.p;
      if ( mNext == (UFG::PartCompositeBuilder *)&UFG::PartCompositeBuilder::sInstance->mPendingBuilds )
        goto LABEL_6;
    }
    goto LABEL_15;
  }
LABEL_6:
  if ( UFG::DUIContext::Collapsible(dui, "Part Selection", &this->mCollapseTemplate) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::PartCustomizer::BuildPartSelectionUI(this, dui);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( !this->mLoading && !this->mLoadStatusChanged )
  {
    if ( UFG::DUIContext::Collapsible(dui, "Part Customization", &this->mCollapseInstance) )
    {
      UFG::DUIContext::BeginIndent(dui);
      UFG::PartCustomizer::BuildPartEditUI(this, dui);
      UFG::DUIContext::EndIndent(dui);
    }
    if ( UFG::DUIContext::Collapsible(dui, "Scaling Regions", &this->mCollapseScaling) )
    {
      UFG::DUIContext::BeginIndent(dui);
      UFG::PartCustomizer::BuildScalingUI(this, dui);
      UFG::DUIContext::EndIndent(dui);
    }
  }
}

// File Line: 549
// RVA: 0x156760
char __fastcall UFG::PartCustomizer::ApplySelectionToInstance(
        UFG::PartCustomizer *this,
        UFG::PartCustomizer::PartSelection *selection,
        UFG::PartTemplateInstance::PartEntry *entry)
{
  UFG::PartDefinition *mPart; // rsi
  unsigned int mUID; // ebx
  int mTextureSetSelectionIndex; // ecx
  UFG::qSymbolUC *v7; // rcx
  unsigned __int64 v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PartDefinition::CompositeData *p_mCompositeData; // rbp
  unsigned int mNumItems; // ecx
  UFG::PartDefinition::TextureAlternate *mItems; // rax

  mPart = selection->mPart;
  mUID = UFG::gNullQSymbolUC.mUID;
  if ( mPart )
  {
    mTextureSetSelectionIndex = selection->mTextureSetSelectionIndex;
    v7 = mTextureSetSelectionIndex <= 0
       ? &UFG::gNullQSymbolUC
       : (UFG::qSymbolUC *)&mPart->mTextureAlternates.mData.mItems[mTextureSetSelectionIndex - 1];
    mUID = v7->mUID;
    if ( entry->mPart.mData == mPart
      && entry->mTextureSet.mUID == mUID
      && entry->mDiffuseColours.mData.mNumItems == mPart->mCompositeData.mDiffuseChannelDefaults.mData.mNumItems
      && entry->mSpecularValues.mData.mNumItems == mPart->mCompositeData.mSpecularChannelDefaults.mData.mNumItems )
    {
      return 0;
    }
  }
  entry->mTextureSet = UFG::gNullQSymbolUC;
  UFG::OnUnloadHandle((char *)entry);
  v9 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  entry->mPart.mNameUID = -1i64;
  entry->mPart.mTypeUID = v9;
  entry->mTextureSet.mUID = mUID;
  if ( (entry->mDiffuseColours.mData.mFlags & 2) == 0 )
    operator delete[](entry->mDiffuseColours.mData.mItems);
  v10 = 0;
  entry->mDiffuseColours.mData.mItems = 0i64;
  *(_QWORD *)&entry->mDiffuseColours.mData.mNumItems = 0i64;
  if ( (entry->mSpecularValues.mData.mFlags & 2) == 0 )
    operator delete[](entry->mSpecularValues.mData.mItems);
  entry->mSpecularValues.mData.mItems = 0i64;
  *(_QWORD *)&entry->mSpecularValues.mData.mNumItems = 0i64;
  if ( mPart )
  {
    UFG::qReflectHandleBase::Init(&entry->mPart, entry->mPart.mTypeUID, mPart->mBaseNode.mUID);
    v11 = entry->mTextureSet.mUID;
    p_mCompositeData = &mPart->mCompositeData;
    if ( v11 != UFG::gNullQSymbolUC.mUID )
    {
      mNumItems = mPart->mTextureAlternates.mData.mNumItems;
      if ( mNumItems )
      {
        mItems = mPart->mTextureAlternates.mData.mItems;
        while ( mItems->mId.mUID != v11 )
        {
          ++v10;
          ++mItems;
          if ( v10 >= mNumItems )
            goto LABEL_22;
        }
        p_mCompositeData = &mItems->mCompositeData;
      }
    }
LABEL_22:
    UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(entry, p_mCompositeData);
    UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(entry, p_mCompositeData);
  }
  return 1;
}

// File Line: 595
// RVA: 0x156450
void __fastcall UFG::PartCustomizer::ApplyCustomization(UFG::PartCustomizer *this)
{
  UFG::PartTemplateInstance *mInstance; // rcx
  UFG::PartTemplateInstance *v3; // rdx
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *p_mSelectedParts; // rbx
  char v5; // r12
  int v6; // ecx
  UFG::PartCustomizer *mNext; // rax
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v8; // rax
  unsigned int i; // edx
  int j; // edx
  int v11; // ecx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *k; // rax
  int v13; // ecx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *m; // rax
  UFG::PartTemplateInstance *v15; // rsi
  UFG::PartTemplateInstance::SlotEntry *mItems; // rcx
  unsigned int *p_mNumItems; // rdi
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v18; // rax
  unsigned int n; // edx
  int ii; // r14d
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v21; // rdi
  int v22; // ecx
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v23; // rax
  UFG::PartTemplateInstance *v24; // rax
  __int64 v25; // rsi
  int jj; // eax
  bool v27; // al
  unsigned int v28; // edx
  __int64 kk; // rbp
  bool v30; // al

  mInstance = this->mInstance;
  if ( mInstance )
  {
    UFG::qReflectHandleBase::Init(
      &mInstance->mTemplate,
      mInstance->mTemplate.mTypeUID,
      this->mPartTemplate->mBaseNode.mUID);
    v3 = this->mInstance;
    p_mSelectedParts = &this->mSelectedParts;
    v5 = 0;
    v6 = 0;
    mNext = (UFG::PartCustomizer *)this->mSelectedParts.mNode.mNext;
    if ( mNext != (UFG::PartCustomizer *)&this->mSelectedParts )
    {
      do
      {
        mNext = (UFG::PartCustomizer *)mNext->mBaseNode.mUID;
        ++v6;
      }
      while ( mNext != (UFG::PartCustomizer *)p_mSelectedParts );
    }
    if ( v3->mSlots.mData.mNumItems != v6 )
    {
      UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::~qReflectArray<UFG::PartTemplateInstance::SlotEntry>(&v3->mSlots);
      v8 = this->mSelectedParts.mNode.mNext;
      for ( i = 0;
            v8 != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts;
            ++i )
      {
        v8 = v8->mNext;
      }
      UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::Resize(
        &this->mInstance->mSlots,
        i,
        "qReflectArray.Resize");
      v5 = 1;
    }
    for ( j = 0; ; ++j )
    {
      v11 = 0;
      for ( k = this->mSelectedParts.mNode.mNext;
            k != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts;
            ++v11 )
      {
        k = k->mNext;
      }
      if ( j >= v11 )
        break;
      v13 = j;
      for ( m = this->mSelectedParts.mNode.mNext; v13 > 0; --v13 )
      {
        if ( m == (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts )
          break;
        m = m->mNext;
      }
      if ( this->mInstance->mSlots.mData.mItems[j].mSlotName.mUID != HIDWORD(m[1].mPrev) )
      {
        v15 = this->mInstance;
        if ( (v15->mSlots.mData.mFlags & 2) == 0 )
        {
          mItems = v15->mSlots.mData.mItems;
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
        v15->mSlots.mData.mItems = 0i64;
        *(_QWORD *)&v15->mSlots.mData.mNumItems = 0i64;
        v18 = this->mSelectedParts.mNode.mNext;
        for ( n = 0;
              v18 != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts;
              ++n )
        {
          v18 = v18->mNext;
        }
        UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::Resize(
          &this->mInstance->mSlots,
          n,
          "qReflectArray.Resize");
        v5 = 1;
        break;
      }
    }
    for ( ii = 0; ; ++ii )
    {
      v21 = this->mSelectedParts.mNode.mNext;
      v22 = 0;
      v23 = (UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *)v21;
      if ( v21 != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts )
      {
        do
        {
          v23 = (UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *)v23->mNode.mNext;
          ++v22;
        }
        while ( v23 != p_mSelectedParts );
      }
      v24 = this->mInstance;
      if ( ii >= v22 )
        break;
      v25 = (__int64)&v24->mSlots.mData.mItems[ii];
      for ( jj = ii; jj > 0; --jj )
      {
        if ( v21 == (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)p_mSelectedParts )
          break;
        v21 = v21->mNext;
      }
      v27 = UFG::PartCustomizer::ApplySelectionToInstance(
              this,
              (UFG::PartCustomizer::PartSelection *)&v21[1].mNext,
              (UFG::PartTemplateInstance::PartEntry *)(v25 + 8));
      v28 = (unsigned int)v21[2].mNext;
      v5 |= v27;
      if ( *(_DWORD *)(v25 + 96) != v28 )
      {
        UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry>::Resize(
          (UFG::qReflectArray<UFG::PartTemplateInstance::PartEntry> *)(v25 + 88),
          v28,
          "qReflectArray.Resize");
        v5 = 1;
      }
      for ( kk = 0i64; (unsigned int)kk < LODWORD(v21[2].mNext); v5 |= v30 )
      {
        v30 = UFG::PartCustomizer::ApplySelectionToInstance(
                this,
                (UFG::PartCustomizer::PartSelection *)&v21[3].mPrev[(unsigned int)kk],
                (UFG::PartTemplateInstance::PartEntry *)(*(_QWORD *)(v25 + 88) + 80 * kk));
        kk = (unsigned int)(kk + 1);
      }
    }
    v24->mCompositeDirty = 1;
    UFG::PartCustomizer::sSaveInstanceData(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sConfigureParts(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sQueueCompositeBuild(this->mSimObject, v5, this->mInstance);
  }
}

// File Line: 660
// RVA: 0x15B6C0
void __fastcall UFG::PartCustomizer::UpdateUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartLoader *p_mPartLoader; // rbx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *i; // r9
  UFG::PartDefinition *mPrev; // r8
  int mNext_high; // eax
  UFG::qSymbolUC *p_mId; // rdx
  unsigned int j; // r8d
  __int64 v10; // rax
  UFG::PartDefinition *v11; // r10
  int v12; // eax
  UFG::qSymbolUC *v13; // rdx
  unsigned int mPartRequestCount; // edx
  unsigned int v15; // r11d
  UFG::PartRequest **mPartRequests; // rcx

  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::PartCustomizer::BuildUI(this, dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  if ( this->mLoadStatusChanged )
  {
    p_mPartLoader = &this->mPartLoader;
    UFG::PartLoader::Unload(&this->mPartLoader);
    this->mPartLoader.mPartCount = 0;
    for ( i = this->mSelectedParts.mNode.mNext;
          i != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)&this->mSelectedParts;
          i = i->mNext )
    {
      mPrev = (UFG::PartDefinition *)i[2].mPrev;
      if ( mPrev )
      {
        mNext_high = HIDWORD(i[1].mNext);
        if ( mNext_high <= 0 )
          p_mId = &UFG::gNullQSymbolUC;
        else
          p_mId = &mPrev->mTextureAlternates.mData.mItems[mNext_high - 1].mId;
        this->mPartLoader.mParts[this->mPartLoader.mPartCount] = mPrev;
        p_mPartLoader->mTextureSets[this->mPartLoader.mPartCount++] = (UFG::qSymbolUC)p_mId->mUID;
      }
      for ( j = 0; j < LODWORD(i[2].mNext); ++j )
      {
        v10 = (__int64)&i[3].mPrev[j];
        v11 = *(UFG::PartDefinition **)(v10 + 8);
        if ( v11 )
        {
          v12 = *(_DWORD *)(v10 + 4);
          if ( v12 <= 0 )
            v13 = &UFG::gNullQSymbolUC;
          else
            v13 = &v11->mTextureAlternates.mData.mItems[v12 - 1].mId;
          this->mPartLoader.mParts[this->mPartLoader.mPartCount] = v11;
          p_mPartLoader->mTextureSets[this->mPartLoader.mPartCount++] = (UFG::qSymbolUC)v13->mUID;
        }
      }
    }
    UFG::PartLoader::QueueLoad(&this->mPartLoader);
    *(_WORD *)&this->mLoadStatusChanged = 256;
  }
  else if ( this->mLoading )
  {
    mPartRequestCount = this->mPartLoader.mPartRequestCount;
    if ( mPartRequestCount )
    {
      v15 = 0;
      mPartRequests = this->mPartLoader.mPartRequests;
      while ( (*mPartRequests)->mLoadStatus == Loaded )
      {
        ++v15;
        ++mPartRequests;
        if ( v15 >= mPartRequestCount )
          goto LABEL_22;
      }
    }
    if ( !this->mPartLoader.mPartCount )
    {
LABEL_22:
      UFG::PartCustomizer::ApplyCustomization(this);
      this->mLoading = 0;
    }
  }
  else if ( this->mCompositeDirty )
  {
    this->mInstance->mCompositeDirty = 1;
    UFG::PartCustomizer::sSaveInstanceData(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sQueueCompositeBuild(this->mSimObject, 0, this->mInstance);
    this->mCompositeDirty = 0;
  }
  else if ( this->mScalingDirty )
  {
    UFG::PartCustomizer::sSaveInstanceData(this->mSimObject, this->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(this->mSimObject, this->mInstance);
    this->mScalingDirty = 1;
  }
}

