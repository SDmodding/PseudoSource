// File Line: 11
// RVA: 0x1466BD0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PartCustomizer_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PartCustomizer", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::PartCustomizer",
    v0);
  UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PartCustomizer>::`vftable;
  UFG::qReflectInventory<UFG::PartCustomizer>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PartCustomizer_UFG::DUIWindow_::sInventory__);
}

// File Line: 31
// RVA: 0x159A90
void __fastcall UFG::PartCustomizer::OnPropertyChanged(char *object, UFG::qReflectField *field, UFG::qReflectType *field_type, char *field_data, void *user_data)
{
  *((_BYTE *)user_data + 420) = 1;
}

// File Line: 70
// RVA: 0x154000
void __fastcall UFG::PartCustomizer::PartCustomizer(UFG::PartCustomizer *this)
{
  UFG::PartCustomizer *v1; // rbx
  unsigned __int64 v2; // rax
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v3; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::PartCustomizer,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::PartCustomizer", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &v1->mNotification,
    v2,
    UFG::PartCustomizer::OnPropertyChanged,
    (void (__fastcall *)(char *, void *))_,
    0i64);
  v3 = &v1->mSelectedParts;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  *(_QWORD *)&v1->mCurrentPartTemplate = 0i64;
  v1->mCurrentPartEditIndex = 0;
  *(_DWORD *)&v1->mCollapseTemplate = 16843009;
  *(_DWORD *)&v1->mCollapseDiffuseChannels = 257;
  v1->mCompositeDirty = 0;
  UFG::PartLoader::PartLoader(&v1->mPartLoader);
  v1->mSimObject = 0i64;
  v1->mInstance = 0i64;
  UFG::qString::Set(&v1->mTitle, "PartCustomizer");
  v1->mScrollPos = 0i64;
  *(_QWORD *)&v1->mRect.mX = 730i64;
  v1->mRect.mW = 550;
  v1->mRect.mH = 720;
  v1->mNotification.mUserData = v1;
  UFG::PartCustomizer::sInstance = v1;
}

// File Line: 83
// RVA: 0x1550B0
void __fastcall UFG::PartCustomizer::~PartCustomizer(UFG::PartCustomizer *this)
{
  UFG::PartCustomizer *v1; // rdi
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v2; // rcx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v3; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::PartCustomizer::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::PartCustomizer::sCustomizeComplete(this->mSimObject, this->mInstance);
  UFG::PartCustomizer::sSetCameraOperation(v1->mSimObject, 0i64);
  UFG::PartCustomizer::sInstance = 0i64;
  UFG::PartLoader::Unload(&v1->mPartLoader);
  `eh vector destructor iterator(v1->mPartLoader.mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))_);
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0>::DeleteNodes(&v1->mSelectedParts);
  v2 = v1->mSelectedParts.mNode.mPrev;
  v3 = v1->mSelectedParts.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mSelectedParts.mNode.mPrev = &v1->mSelectedParts.mNode;
  v1->mSelectedParts.mNode.mNext = &v1->mSelectedParts.mNode;
  UFG::EditNotification::~EditNotification(&v1->mNotification);
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 121
// RVA: 0x15AD60
void __fastcall UFG::PartCustomizer::SetupFromTemplate(UFG::PartCustomizer *this)
{
  UFG::PartCustomizer *v1; // rbp
  unsigned int v2; // er14
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v3; // rcx
  UFG::PartTemplateInstance *v4; // rbx
  UFG::PartTemplateInstance *v5; // rbx
  UFG::PartTemplate::ScalingRegion *v6; // rdi

  v1 = this;
  v2 = 0;
  v3 = &this->mSelectedParts;
  HIDWORD(v3[1].mNode.mNext) = 0;
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0>::DeleteNodes(v3);
  UFG::PartCustomizer::AssignSlotDataRecursive(v1, &v1->mPartTemplate->mSlotTree);
  v4 = v1->mInstance;
  if ( v4->mScalingRegions.mData.mNumItems != v1->mPartTemplate->mScalingRegions.mData.mNumItems )
  {
    if ( !(v4->mScalingRegions.mData.mFlags & 2) )
      operator delete[](v4->mScalingRegions.mData.mItems);
    v4->mScalingRegions.mData.mItems = 0i64;
    *(_QWORD *)&v4->mScalingRegions.mData.mNumItems = 0i64;
    if ( v1->mPartTemplate->mScalingRegions.mData.mNumItems > 0 )
    {
      do
      {
        v5 = v1->mInstance;
        v6 = v1->mPartTemplate->mScalingRegions.mData.mItems;
        UFG::qReflectArray<float>::Resize(
          &v5->mScalingRegions,
          v5->mScalingRegions.mData.mNumItems + 1,
          "qReflectArray.Add");
        v5->mScalingRegions.mData.mItems[v5->mScalingRegions.mData.mNumItems - 1] = v6[v2++].mDefaultScale;
      }
      while ( v2 < v1->mPartTemplate->mScalingRegions.mData.mNumItems );
    }
  }
}

// File Line: 170
// RVA: 0x156A50
void __fastcall UFG::PartCustomizer::AssignSlotDataRecursive(UFG::PartCustomizer *this, UFG::PartTemplate::Slot *slot)
{
  UFG::PartTemplate::Slot *v2; // rbx
  unsigned int v3; // edi
  int v4; // er8
  UFG::PartCustomizer *i; // rax
  char *v6; // rax
  char *v7; // rcx
  unsigned __int64 v8; // rax
  unsigned int v9; // esi
  unsigned int v10; // er9
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
  UFG::PartTemplateInstance *v21; // rax
  __int64 v22; // rcx
  signed __int64 v23; // rcx
  int v24; // edx
  __int64 v25; // r9
  int v26; // eax
  unsigned int v27; // er8
  unsigned int v28; // er10
  char *v29; // r10
  int v30; // eax
  _DWORD *v31; // r9
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int v34; // ebx
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // ebx
  signed __int64 v39; // rcx
  signed __int64 v40; // r11
  signed __int64 v41; // rdx
  int v42; // eax
  __int64 v43; // r9
  int v44; // ecx
  unsigned int v45; // er8
  unsigned int v46; // er10
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v47; // rcx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v48; // rax
  char *mem; // [rsp+28h] [rbp-21h]
  char *v50; // [rsp+30h] [rbp-19h]
  signed __int64 v51; // [rsp+38h] [rbp-11h]
  unsigned int v52; // [rsp+40h] [rbp-9h]
  UFG::qArray<UFG::PartDefinition *,0> v53; // [rsp+48h] [rbp-1h]
  UFG::PartDefinition *v54; // [rsp+58h] [rbp+Fh]
  char *v55; // [rsp+60h] [rbp+17h]
  UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *v56; // [rsp+68h] [rbp+1Fh]
  __int64 v57; // [rsp+70h] [rbp+27h]
  UFG::PartCustomizer *v58; // [rsp+B0h] [rbp+67h]
  UFG::PartTemplate::Slot *v59; // [rsp+B8h] [rbp+6Fh]
  unsigned int v60; // [rsp+C0h] [rbp+77h]
  signed __int64 v61; // [rsp+C0h] [rbp+77h]
  int v62; // [rsp+C0h] [rbp+77h]
  unsigned int v63; // [rsp+C8h] [rbp+7Fh]

  v59 = slot;
  v58 = this;
  v57 = -2i64;
  v2 = slot;
  v56 = &this->mSelectedParts;
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
    if ( v53.size > 0 )
    {
      v12 = 2;
      v13 = v59;
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
            v13 = v59;
          }
        }
        v9 = v15;
        *(_QWORD *)&v11[8 * v52] = v54;
        v63 = ++v10;
      }
      while ( v10 < v53.size );
      v3 = 0;
    }
    v21 = v58->mInstance;
    v22 = (unsigned int)v58->mCurrentPartDepth;
    if ( (signed int)v21->mSlots.mData.mNumItems <= (signed int)v22 )
    {
      v29 = v50;
      *((_DWORD *)v50 + 6) = v60;
      *((_DWORD *)v50 + 7) = 0;
      *((_QWORD *)v50 + 4) = *(_QWORD *)&v11[8 * v60];
    }
    else
    {
      v23 = (signed __int64)&v21->mSlots.mData.mItems[v22];
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
      v31 = v29 + 40;
      v61 = (signed __int64)(v29 + 40);
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
          v31 = (_DWORD *)v61;
          v29 = v50;
        }
        *v31 = v34;
      }
      v38 = 0;
      v62 = 0;
      v39 = v51;
      if ( *(_DWORD *)(v51 + 96) )
      {
        do
        {
          v40 = *((_QWORD *)v29 + 6) + 16i64 * v38;
          v41 = *(_QWORD *)(v39 + 88) + 80i64 * v38;
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
          v39 = v51;
        }
        while ( v38 < *(_DWORD *)(v51 + 96) );
      }
    }
    v29[16] = v58->mCurrentPartDepth == 0;
    v47 = v56;
    v48 = v56->mNode.mPrev;
    v48->mNext = (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v29;
    *(_QWORD *)v29 = v48;
    *((_QWORD *)v29 + 1) = v47;
    v47->mNode.mPrev = (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v29;
    if ( v53.p )
      operator delete[](v53.p);
    v53.p = 0i64;
    *(_QWORD *)&v53.size = 0i64;
    if ( mem )
      operator delete[](mem);
    this = v58;
    v2 = v59;
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
void __fastcall UFG::PartCustomizer::PopulateSelectionUI(UFG::PartCustomizer *this, UFG::DUIContext *dui, UFG::PartCustomizer::PartSelection *selection, UFG::qList<UFG::qString,UFG::qString,1,0> *partNames, UFG::qArray<UFG::PartDefinition *,0> *parts)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v5; // rbx
  UFG::PartCustomizer::PartSelection *v6; // r14
  UFG::DUIContext *v7; // r15
  UFG::PartCustomizer *v8; // rsi
  bool v9; // al
  UFG::qArray<UFG::PartDefinition *,0> *v10; // rdx
  UFG::PartDefinition *v11; // rbx
  char *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  __int64 v16; // rdi
  char *v17; // rax
  signed __int64 v18; // rdx
  const char *v19; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  int v23; // ecx
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+40h] [rbp-10h]
  int current_index; // [rsp+80h] [rbp+30h]

  v5 = partNames;
  v6 = selection;
  v7 = dui;
  v8 = this;
  UFG::DUIContext::BeginIndent(dui);
  current_index = v6->mPartSelectionIndex;
  v9 = UFG::DUIContext::ComboBox(v7, &current_index, v5, 0i64, 0xFFFFFFFF);
  v10 = parts;
  if ( v9 && current_index >= 0 && current_index < (signed int)parts->size )
  {
    v6->mPartSelectionIndex = current_index;
    v6->mTextureSetSelectionIndex = 0;
    v8->mCurrentPartEditIndex = v8->mCurrentPartDepth + 1;
    v8->mLoadStatusChanged = 1;
  }
  if ( (signed int)v10->size <= v6->mPartSelectionIndex )
    v11 = 0i64;
  else
    v11 = v10->p[v6->mPartSelectionIndex];
  v6->mPart = v11;
  if ( v11 && v11->mTextureAlternates.mData.mNumItems )
  {
    UFG::DUIContext::Label(v7, "Select Texture Set");
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
    v15 = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v14;
    v14->mPrev = v15;
    v14->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v14;
    v16 = 0i64;
    if ( v11->mTextureAlternates.mData.mNumItems )
    {
      do
      {
        v17 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        if ( v17 )
        {
          v18 = (signed __int64)&v11->mTextureAlternates.mData.mItems[v16];
          if ( *(_DWORD *)(v18 + 16) )
            v19 = *(const char **)(v18 + 8);
          else
            v19 = &customWorldMapCaption;
          UFG::qString::qString((UFG::qString *)v17, v19);
          v21 = v20;
        }
        else
        {
          v21 = 0i64;
        }
        v22 = options.mNode.mPrev;
        options.mNode.mPrev->mNext = v21;
        v21->mPrev = v22;
        v21->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        options.mNode.mPrev = v21;
        v16 = (unsigned int)(v16 + 1);
      }
      while ( (unsigned int)v16 < v11->mTextureAlternates.mData.mNumItems );
    }
    LODWORD(parts) = v6->mTextureSetSelectionIndex;
    if ( UFG::DUIContext::ComboBox(v7, (int *)&parts, &options, 0i64, 0xFFFFFFFF) )
    {
      v23 = (signed int)parts;
      if ( (signed int)parts >= 0 )
      {
        v8->mCurrentPartEditIndex = v8->mCurrentPartDepth + 1;
        v6->mTextureSetSelectionIndex = v23;
        v8->mLoadStatusChanged = 1;
      }
    }
    for ( i = (UFG::qString *)options.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
          i = (UFG::qString *)options.mNode.mNext )
    {
      v25 = i->mPrev;
      v26 = i->mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    v27 = options.mNode.mPrev;
    v28 = options.mNode.mNext;
    options.mNode.mPrev->mNext = options.mNode.mNext;
    v28->mPrev = v27;
    options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  }
  UFG::DUIContext::EndIndent(v7);
}

// File Line: 282
// RVA: 0x157CE0
void __fastcall UFG::PartCustomizer::BuildSlotTree(UFG::PartCustomizer *this, UFG::DUIContext *dui, UFG::PartTemplate::Slot *slot, bool parent_expanded)
{
  bool v4; // bl
  UFG::PartTemplate::Slot *v5; // rsi
  UFG::PartCustomizer *v6; // rdi
  char *v7; // r8
  int v8; // eax
  __int64 v9; // rsi
  unsigned int v10; // edi
  char *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  unsigned __int64 v15; // rax
  char *v16; // rax
  signed int v17; // ebx
  unsigned int v18; // eax
  char *v19; // rsi
  const char *v20; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v23; // rax
  unsigned int v24; // esi
  unsigned int v25; // ebx
  unsigned __int64 v26; // rax
  char *v27; // rcx
  UFG::PartDefinition **v28; // r10
  _QWORD *v29; // rdx
  char *v30; // r9
  __int64 v31; // r8
  UFG::qArray<UFG::PartCustomizer::PartSelection,0> *v32; // rbx
  unsigned int v33; // esi
  __int64 v34; // rdi
  UFG::DUIContext *v35; // rsi
  unsigned int v36; // esi
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  UFG::PartCustomizer::PartSelection *v39; // rcx
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v44; // rax
  bool v45; // cl
  UFG::PartCustomizer *v46; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> partNames; // [rsp+30h] [rbp-59h]
  UFG::qArray<UFG::PartDefinition *,0> parts; // [rsp+40h] [rbp-49h]
  unsigned int v49; // [rsp+50h] [rbp-39h]
  UFG::qArray<UFG::PartDefinition *,0> v50; // [rsp+58h] [rbp-31h]
  char *v51; // [rsp+68h] [rbp-21h]
  int v52; // [rsp+70h] [rbp-19h]
  __int64 v53; // [rsp+78h] [rbp-11h]
  UFG::qReflectObject *v54; // [rsp+80h] [rbp-9h]
  __int64 v55; // [rsp+88h] [rbp-1h]
  UFG::qString result; // [rsp+90h] [rbp+7h]
  UFG::PartCustomizer *v57; // [rsp+F0h] [rbp+67h]
  UFG::DUIContext *duia; // [rsp+F8h] [rbp+6Fh]
  UFG::PartTemplate::Slot *v59; // [rsp+100h] [rbp+77h]
  char v60; // [rsp+108h] [rbp+7Fh]

  v59 = slot;
  duia = dui;
  v57 = this;
  v55 = -2i64;
  v4 = parent_expanded;
  v5 = slot;
  v6 = this;
  UFG::DUIContext::BeginIndent(dui);
  if ( v5->mName.mText.mData.mNumItems )
    v7 = v5->mName.mText.mData.mItems;
  else
    v7 = &customWorldMapCaption;
  UFG::qString::FormatEx(&result, "Slot: %s", v7);
  v8 = v6->mCurrentPartDepth;
  v9 = (__int64)v6->mSelectedParts.mNode.mNext;
  v53 = (__int64)v6->mSelectedParts.mNode.mNext;
  if ( v8 > 0 )
  {
    do
    {
      if ( (UFG::qList<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper,1,0> *)v9 == &v6->mSelectedParts )
        break;
      --v8;
      v9 = *(_QWORD *)(v9 + 8);
    }
    while ( v8 > 0 );
    v53 = v9;
  }
  v10 = 0;
  if ( v4 && UFG::DUIContext::Collapsible(duia, result.mData, (bool *)(v9 + 16)) )
  {
    v60 = 1;
    partNames.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    parts.p = 0i64;
    *(_QWORD *)&parts.size = 0i64;
    v11 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v51 = v11;
    if ( v11 )
    {
      UFG::qString::qString((UFG::qString *)v11, "Empty");
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v14 = partNames.mNode.mPrev;
    partNames.mNode.mPrev->mNext = v13;
    v13->mPrev = v14;
    v13->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mPrev = v13;
    v15 = 16i64;
    if ( !is_mul_ok(2ui64, 8ui64) )
      v15 = -1i64;
    v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
    parts.p = (UFG::PartDefinition **)v16;
    parts.capacity = 2;
    v17 = 1;
    parts.size = 1;
    *(_QWORD *)v16 = 0i64;
    v50.p = 0i64;
    *(_QWORD *)&v50.size = 0i64;
    UFG::PartCustomizer::sGetAvailableParts(&v50, &v59->mSlotName);
    v18 = 0;
    v49 = 0;
    if ( v50.size > 0 )
    {
      do
      {
        v54 = (UFG::qReflectObject *)&v50.p[v18]->vfptr;
        v19 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v51 = v19;
        if ( v19 )
        {
          v20 = UFG::qReflectObject::GetName(v54);
          UFG::qString::qString((UFG::qString *)v19, v20);
          v22 = v21;
        }
        else
        {
          v22 = 0i64;
        }
        v23 = partNames.mNode.mPrev;
        partNames.mNode.mPrev->mNext = v22;
        v22->mPrev = v23;
        v22->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
        partNames.mNode.mPrev = v22;
        v52 = v17;
        v24 = v17 + 1;
        if ( v17 + 1 > parts.capacity )
        {
          v25 = 1;
          if ( parts.capacity )
            v25 = 2 * parts.capacity;
          for ( ; v25 < v24; v25 *= 2 )
            ;
          if ( v25 <= 2 )
            v25 = 2;
          if ( v25 - v24 > 0x10000 )
            v25 = v24 + 0x10000;
          if ( v25 != parts.size )
          {
            v26 = 8i64 * v25;
            if ( !is_mul_ok(v25, 8ui64) )
              v26 = -1i64;
            v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
            v51 = v27;
            v28 = parts.p;
            if ( parts.p )
            {
              if ( parts.size )
              {
                v29 = v27;
                v30 = (char *)((char *)parts.p - v27);
                v31 = parts.size;
                do
                {
                  *v29 = *(_QWORD *)((char *)v29 + (_QWORD)v30);
                  ++v29;
                  --v31;
                }
                while ( v31 );
              }
              operator delete[](v28);
              v27 = v51;
            }
            parts.p = (UFG::PartDefinition **)v27;
            parts.capacity = v25;
          }
        }
        v17 = v24;
        parts.size = v24;
        parts.p[v52] = (UFG::PartDefinition *)v54;
        v18 = v49 + 1;
        v49 = v18;
      }
      while ( v18 < v50.size );
      v9 = v53;
    }
    UFG::PartCustomizer::PopulateSelectionUI(
      v57,
      duia,
      (UFG::PartCustomizer::PartSelection *)(v9 + 24),
      &partNames,
      &parts);
    UFG::DUIContext::BeginIndent(duia);
    v32 = (UFG::qArray<UFG::PartCustomizer::PartSelection,0> *)(v9 + 40);
    if ( *(_DWORD *)(v9 + 40) )
    {
      UFG::DUIContext::Label(duia, "Layers:");
      v33 = 0;
      if ( v32->size > 0 )
      {
        v34 = v53;
        do
          UFG::PartCustomizer::PopulateSelectionUI(
            v57,
            duia,
            (UFG::PartCustomizer::PartSelection *)(*(_QWORD *)(v34 + 48) + 16i64 * v33++),
            &partNames,
            &parts);
        while ( v33 < v32->size );
        v10 = 0;
      }
    }
    v35 = duia;
    if ( (unsigned __int8)UFG::DUIContext::Button(duia, "Add Layer", 0x10u) )
    {
      v36 = v32->size + 1;
      v37 = v32->capacity;
      if ( v36 > v37 )
      {
        if ( v37 )
          v38 = 2 * v37;
        else
          v38 = 1;
        for ( ; v38 < v36; v38 *= 2 )
          ;
        if ( v38 - v36 > 0x10000 )
          v38 = v32->size + 65537;
        UFG::qArray<UFG::PartCustomizer::PartSelection,0>::Reallocate(v32, v38, "qArray.Add");
      }
      v32->size = v36;
      v35 = duia;
    }
    if ( (unsigned __int8)UFG::DUIContext::Button(v35, "Delete Layers", 0x10u) )
    {
      v39 = v32->p;
      if ( v39 )
        operator delete[](v39);
      v32->p = 0i64;
      *(_QWORD *)&v32->size = 0i64;
      v57->mLoadStatusChanged = 1;
    }
    UFG::DUIContext::EndIndent(v35);
    if ( v50.p )
      operator delete[](v50.p);
    v50.p = 0i64;
    *(_QWORD *)&v50.size = 0i64;
    if ( parts.p )
      operator delete[](parts.p);
    parts.p = 0i64;
    *(_QWORD *)&parts.size = 0i64;
    for ( i = (UFG::qString *)partNames.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)partNames.mNode.mNext != &partNames;
          i = (UFG::qString *)partNames.mNode.mNext )
    {
      v41 = i->mPrev;
      v42 = i->mNext;
      v41->mNext = v42;
      v42->mPrev = v41;
      i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    v43 = partNames.mNode.mPrev;
    v44 = partNames.mNode.mNext;
    partNames.mNode.mPrev->mNext = partNames.mNode.mNext;
    v44->mPrev = v43;
    partNames.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    partNames.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&partNames;
    v45 = 1;
  }
  else
  {
    v45 = 0;
    v60 = 0;
    v35 = duia;
  }
  v46 = v57;
  ++v46->mCurrentPartDepth;
  if ( v59->mChildren.mData.mNumItems )
  {
    do
    {
      UFG::PartCustomizer::BuildSlotTree(v46, v35, &v59->mChildren.mData.mItems[v10++], v45);
      v46 = v57;
      v45 = v60;
    }
    while ( v10 < v59->mChildren.mData.mNumItems );
  }
  UFG::DUIContext::EndIndent(v35);
  UFG::qString::~qString(&result);
}

// File Line: 345
// RVA: 0x157630
void __fastcall UFG::PartCustomizer::BuildPartSelectionUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::PartCustomizer *v3; // r12
  _BYTE *v4; // r14
  signed int v5; // esi
  unsigned int v6; // er15
  unsigned __int64 v7; // rbx
  UFG::qReflectWarehouse *v8; // rax
  UFG::qReflectInventoryBase *v9; // rax
  UFG::qTree64Base *v10; // rax
  UFG::qReflectObject *v11; // r13
  UFG::qTree64Base *v12; // r12
  char *v13; // rbx
  const char *v14; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  unsigned int v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // ebx
  unsigned __int64 v21; // rax
  char *v22; // rax
  __int64 v23; // r15
  _QWORD *v24; // rdx
  __int64 v25; // r8
  UFG::qTree64Base *v26; // rax
  float v27; // xmm0_4
  bool v28; // zf
  __int64 v29; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+38h] [rbp-30h]
  __int64 v36; // [rsp+48h] [rbp-20h]
  __int64 v37; // [rsp+50h] [rbp-18h]
  UFG::PartCustomizer *v38; // [rsp+B0h] [rbp+48h]
  UFG::DUIContext *v39; // [rsp+B8h] [rbp+50h]
  int current_index; // [rsp+C0h] [rbp+58h]
  UFG::qTree64Base *v41; // [rsp+C8h] [rbp+60h]

  v39 = dui;
  v38 = this;
  v2 = dui;
  v3 = this;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v4 = 0i64;
  v37 = 0i64;
  v5 = 0;
  v36 = 0i64;
  v6 = 0;
  v7 = UFG::qStringHash64("UFG::PartTemplate", 0xFFFFFFFFFFFFFFFFui64);
  v8 = UFG::qReflectWarehouse::Instance();
  v9 = UFG::qReflectWarehouse::GetInventory(v8, v7);
  v41 = &v9->mItems.mTree;
  v10 = UFG::qTree64Base::GetHead(&v9->mItems.mTree);
  if ( v10 )
  {
    v11 = (UFG::qReflectObject *)&v10[-1].mCount;
    if ( v10 != (UFG::qTree64Base *)8 )
    {
      v12 = v41;
      do
      {
        v13 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v41 = (UFG::qTree64Base *)v13;
        if ( v13 )
        {
          v14 = UFG::qReflectObject::GetName(v11);
          UFG::qString::qString((UFG::qString *)v13, v14);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        v17 = options.mNode.mPrev;
        options.mNode.mPrev->mNext = v16;
        v16->mPrev = v17;
        v16->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
        options.mNode.mPrev = v16;
        v18 = v5;
        LODWORD(v41) = v5;
        v19 = v5 + 1;
        if ( v5 + 1 > v6 )
        {
          v20 = 1;
          if ( v6 )
            v20 = 2 * v6;
          for ( ; v20 < v19; v20 *= 2 )
            ;
          if ( v20 <= 2 )
            v20 = 2;
          if ( v20 - v19 > 0x10000 )
            v20 = v5 + 65537;
          if ( v20 != v5 )
          {
            v21 = 8i64 * v20;
            if ( !is_mul_ok(v20, 8ui64) )
              v21 = -1i64;
            v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
            v23 = (__int64)v22;
            if ( v4 )
            {
              if ( v5 )
              {
                v24 = v22;
                v25 = (unsigned int)v5;
                do
                {
                  *v24 = *(_QWORD *)((char *)v24 + v4 - v22);
                  ++v24;
                  --v25;
                }
                while ( v25 );
              }
              operator delete[](v4);
            }
            v4 = (_BYTE *)v23;
            v37 = v23;
            v6 = v20;
            HIDWORD(v36) = v20;
            v18 = (unsigned int)v41;
          }
        }
        ++v5;
        LODWORD(v36) = v19;
        *(_QWORD *)&v4[8 * v18] = v11;
        v26 = UFG::qTree64Base::GetNext(v12, &v11->mBaseNode);
        if ( !v26 )
          break;
        v11 = (UFG::qReflectObject *)&v26[-1].mCount;
      }
      while ( v26 != (UFG::qTree64Base *)8 );
      v3 = v38;
      v2 = v39;
    }
  }
  v27 = (float)v3->mCurrentPartTemplate;
  if ( v27 >= (float)(v5 - 1) )
    v27 = (float)(v5 - 1);
  current_index = (signed int)v27;
  UFG::DUIContext::Label(v2, "Select a Template");
  v28 = UFG::DUIContext::ComboBox(v2, &current_index, &options, 0i64, 0xFFFFFFFF) == 0;
  v29 = (unsigned int)current_index;
  if ( !v28 && current_index >= 0 )
  {
    v3->mCurrentPartTemplate = current_index;
    v3->mPartTemplate = *(UFG::PartTemplate **)&v4[8 * v29];
    UFG::PartCustomizer::SetupFromTemplate(v3);
    v29 = (unsigned int)current_index;
  }
  if ( v5 > (signed int)v29 && (signed int)v29 >= 0 )
    v3->mPartTemplate = *(UFG::PartTemplate **)&v4[8 * v29];
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
  v37 = 0i64;
  v36 = 0i64;
  for ( i = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        i = (UFG::qString *)options.mNode.mNext )
  {
    v31 = i->mPrev;
    v32 = i->mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v33 = options.mNode.mPrev;
  v34 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v34->mPrev = v33;
}

// File Line: 386
// RVA: 0x157AB0
void __fastcall UFG::PartCustomizer::BuildSlotEntryUI(UFG::PartCustomizer *this, UFG::DUIContext *dui, UFG::PartTemplateInstance::PartEntry *part_entry)
{
  UFG::PartTemplateInstance::PartEntry *v3; // rbx
  UFG::DUIContext *v4; // r14
  UFG::PartCustomizer *v5; // rbp
  UFG::qReflectObject *v6; // rax
  UFG::PartDefinition::CompositeData *v7; // r15
  unsigned int v8; // edx
  __int64 v9; // rdi
  unsigned int v10; // ecx
  unsigned int v11; // er8
  UFG::PartDefinition::CompositeData *v12; // rax
  unsigned int i; // esi
  UFG::qString result; // [rsp+38h] [rbp-60h]

  v3 = part_entry;
  v4 = dui;
  v5 = this;
  v6 = part_entry->mPart.mData;
  v7 = (UFG::PartDefinition::CompositeData *)&v6[1].mHandles;
  v8 = part_entry->mTextureSet.mUID;
  v9 = 0i64;
  if ( v8 != UFG::gNullQSymbolUC.mUID )
  {
    v10 = (unsigned int)v6[2].mBaseNode.mChildren[1];
    v11 = 0;
    if ( v10 )
    {
      v12 = (UFG::PartDefinition::CompositeData *)v6[2].mBaseNode.mChildren[0];
      while ( LODWORD(v12->mAlpha) != v8 )
      {
        ++v11;
        v12 += 2;
        if ( v11 >= v10 )
          goto LABEL_8;
      }
      v7 = v12 + 1;
    }
  }
LABEL_8:
  UFG::DUIContext::BeginIndent(v4);
  if ( v7->mDiffuseChannelDefaults.mData.mNumItems > 0 )
  {
    if ( (unsigned __int8)UFG::DUIContext::Button(v4, "Reset Diffuse Colours to Defaults", 0x10u) )
    {
      UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(v3, v7);
      v5->mCompositeDirty = 1;
    }
    if ( UFG::DUIContext::Collapsible(v4, "Diffuse Colour Channels", &v5->mCollapseDiffuseChannels) )
    {
      for ( i = 0; i < v3->mDiffuseColours.mData.mNumItems; ++i )
      {
        UFG::qString::FormatEx(&result, "Channel %d", i);
        if ( UFG::DUIContext::ColourPicker(v4, result.mData, &v3->mDiffuseColours.mData.mItems[i], 0) )
          v5->mCompositeDirty = 1;
        UFG::qString::~qString(&result);
      }
    }
  }
  if ( v7->mSpecularChannelDefaults.mData.mNumItems )
  {
    if ( (unsigned __int8)UFG::DUIContext::Button(v4, "Reset Specular Colours to Defaults", 0x10u) )
    {
      UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(v3, v7);
      v5->mCompositeDirty = 1;
    }
    if ( UFG::DUIContext::Collapsible(v4, "Specular Colour Channels", &v5->mCollapseSpecularChannels) )
    {
      UFG::DUIContext::BeginIndent(v4);
      if ( v3->mSpecularValues.mData.mNumItems )
      {
        do
        {
          UFG::qString::FormatEx(&result, "Channel %d", (unsigned int)v9);
          if ( UFG::DUIContext::Slider(v4, result.mData, &v3->mSpecularValues.mData.mItems[v9], 0.0, 1.0, 0.0) )
            v5->mCompositeDirty = 1;
          UFG::qString::~qString(&result);
          v9 = (unsigned int)(v9 + 1);
        }
        while ( (unsigned int)v9 < v3->mSpecularValues.mData.mNumItems );
      }
      UFG::DUIContext::EndIndent(v4);
    }
  }
  UFG::DUIContext::EndIndent(v4);
}

// File Line: 445
// RVA: 0x157250
void __fastcall UFG::PartCustomizer::BuildPartEditUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartCustomizer *v2; // r15
  UFG::PartTemplateInstance *v3; // rax
  UFG::PartTemplate *v4; // r13
  _BYTE *v5; // r12
  unsigned int v6; // esi
  unsigned int v7; // er14
  char *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  unsigned int v12; // ecx
  signed __int64 v13; // r13
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  char *v18; // rax
  __int64 v19; // r14
  _QWORD *v20; // rdx
  __int64 v21; // r8
  char *v22; // rbx
  UFG::qSymbolUC *v23; // rdx
  const char *v24; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  int v28; // esi
  float v29; // xmm0_4
  int v30; // eax
  __int64 v31; // rdi
  __int64 v32; // rbx
  UFG::PartTemplateInstance::PartEntry *v33; // r8
  UFG::qReflectObject *v34; // rax
  int v35; // ebx
  unsigned int v36; // esi
  UFG::PartTemplate::Slot *v37; // r14
  UFG::qReflectObject *v38; // rdx
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  UFG::PartTemplate *v44; // [rsp+30h] [rbp-38h]
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+40h] [rbp-28h]
  __int64 v46; // [rsp+50h] [rbp-18h]
  __int64 v47; // [rsp+58h] [rbp-10h]
  unsigned int i; // [rsp+B0h] [rbp+48h]
  UFG::DUIContext *duia; // [rsp+B8h] [rbp+50h]
  int current_index; // [rsp+C0h] [rbp+58h]
  char *v51; // [rsp+C8h] [rbp+60h]

  duia = dui;
  v2 = this;
  v3 = this->mInstance;
  v4 = (UFG::PartTemplate *)v3->mTemplate.mData;
  v44 = (UFG::PartTemplate *)v3->mTemplate.mData;
  v5 = 0i64;
  v47 = 0i64;
  v6 = 0;
  v46 = 0i64;
  v7 = 0;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v8 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v8 )
  {
    UFG::qString::qString((UFG::qString *)v8, "Select Part to Edit");
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v10;
  v10->mPrev = v11;
  v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v10;
  v12 = 0;
  for ( i = 0; v12 < v2->mInstance->mSlots.mData.mNumItems; i = v12 )
  {
    v13 = (signed __int64)&v2->mInstance->mSlots.mData.mItems[v12];
    v14 = v6;
    v15 = v6 + 1;
    if ( v6 + 1 > v7 )
    {
      v16 = 1;
      if ( v7 )
        v16 = 2 * v7;
      for ( ; v16 < v15; v16 *= 2 )
        ;
      if ( v16 <= 2 )
        v16 = 2;
      if ( v16 - v15 > 0x10000 )
        v16 = v6 + 65537;
      if ( v16 != v6 )
      {
        v17 = 8i64 * v16;
        if ( !is_mul_ok(v16, 8ui64) )
          v17 = -1i64;
        v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
        v19 = (__int64)v18;
        if ( v5 )
        {
          if ( v6 )
          {
            v20 = v18;
            v21 = v6;
            do
            {
              *v20 = *(_QWORD *)((char *)v20 + v5 - v18);
              ++v20;
              --v21;
            }
            while ( v21 );
          }
          operator delete[](v5);
        }
        v5 = (_BYTE *)v19;
        v47 = v19;
        v7 = v16;
        HIDWORD(v46) = v16;
        v14 = v6;
      }
    }
    ++v6;
    LODWORD(v46) = v15;
    *(_QWORD *)&v5[8 * v14] = v13;
    v22 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v51 = v22;
    if ( v22 )
    {
      v23 = (UFG::qSymbolUC *)v13;
      v4 = v44;
      v24 = UFG::PartTemplate::GetNameFromSlotIDRecursive(v44, v23, &v44->mSlotTree);
      UFG::qString::qString((UFG::qString *)v22, v24);
      v26 = v25;
    }
    else
    {
      v26 = 0i64;
      v4 = v44;
    }
    v27 = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v26;
    v26->mPrev = v27;
    v26->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v26;
    v12 = i + 1;
  }
  v28 = v6 + 1;
  v29 = (float)v2->mCurrentPartEditIndex;
  if ( v29 >= (float)v28 )
    v29 = (float)v28;
  current_index = (signed int)v29;
  if ( UFG::DUIContext::ComboBox(duia, &current_index, &options, 0i64, 0xFFFFFFFF) && v2->mCurrentPartEditIndex >= 0 )
    v2->mCurrentPartEditIndex = current_index;
  if ( v28 < 0 )
    v28 = 0;
  v30 = v2->mCurrentPartEditIndex;
  if ( v28 < v30 )
    v30 = v28;
  v2->mCurrentPartEditIndex = v30;
  if ( v30 <= 0 )
  {
    v38 = v4->mSlotTree.mCameraSettings.mData;
  }
  else
  {
    v31 = *(_QWORD *)&v5[8 * (v30 - 1)];
    if ( *(_QWORD *)(v31 + 40) )
    {
      UFG::PartCustomizer::BuildSlotEntryUI(v2, duia, (UFG::PartTemplateInstance::PartEntry *)(v31 + 8));
      v32 = 0i64;
      if ( *(_DWORD *)(v31 + 96) )
      {
        do
        {
          v33 = (UFG::PartTemplateInstance::PartEntry *)(*(_QWORD *)(v31 + 88) + 80 * v32);
          if ( v33->mPart.mData )
            UFG::PartCustomizer::BuildSlotEntryUI(v2, duia, v33);
          v32 = (unsigned int)(v32 + 1);
        }
        while ( (unsigned int)v32 < *(_DWORD *)(v31 + 96) );
      }
    }
    if ( v4->mSlotTree.mSlotName.mUID == *(_DWORD *)v31 )
    {
      v34 = v4->mSlotTree.mCameraSettings.mData;
    }
    else
    {
      v35 = 0;
      v36 = v4->mSlotTree.mChildren.mData.mNumItems;
      if ( v36 )
      {
        v37 = v4->mSlotTree.mChildren.mData.mItems;
        while ( 1 )
        {
          v34 = UFG::PartTemplate::GetCameraSettingFromSlotIDRecursive(v4, (UFG::qSymbolUC *)v31, &v37[v35]);
          if ( v34 )
            break;
          if ( ++v35 >= v36 )
            goto LABEL_49;
        }
      }
      else
      {
LABEL_49:
        v34 = 0i64;
      }
    }
    if ( !v34 )
      v34 = v4->mSlotTree.mCameraSettings.mData;
    v38 = v34;
  }
  UFG::PartCustomizer::sSetCameraOperation(v2->mSimObject, v38);
  for ( j = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        j = (UFG::qString *)options.mNode.mNext )
  {
    v40 = j->mPrev;
    v41 = j->mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v42 = options.mNode.mPrev;
  v43 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v43->mPrev = v42;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  if ( v5 )
    operator delete[](v5);
}

// File Line: 498
// RVA: 0x157980
void __fastcall UFG::PartCustomizer::BuildScalingUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::PartTemplateInstance *v2; // r8
  UFG::DUIContext *v3; // rbp
  UFG::PartCustomizer *v4; // rsi
  UFG::qReflectObject *v5; // rdi
  UFG::PartTemplateInstance *v6; // rbx
  __int64 v7; // rbx
  signed __int64 v8; // r8
  float *v9; // rax
  const char *v10; // rdx

  v2 = this->mInstance;
  v3 = dui;
  v4 = this;
  v5 = v2->mTemplate.mData;
  if ( v2->mScalingRegions.mData.mNumItems < LODWORD(v5[2].mBaseNode.mNeighbours[1]) )
  {
    do
    {
      v6 = v4->mInstance;
      UFG::qReflectArray<float>::Resize(
        &v6->mScalingRegions,
        v6->mScalingRegions.mData.mNumItems + 1,
        "qReflectArray.Add");
      v6->mScalingRegions.mData.mItems[v6->mScalingRegions.mData.mNumItems - 1] = 1.0;
    }
    while ( v4->mInstance->mScalingRegions.mData.mNumItems < LODWORD(v5[2].mBaseNode.mNeighbours[1]) );
  }
  v7 = 0i64;
  if ( LODWORD(v5[2].mBaseNode.mNeighbours[1]) )
  {
    do
    {
      v8 = (signed __int64)&v5[2].mBaseNode.mNeighbours[0][v7];
      v9 = &v4->mInstance->mScalingRegions.mData.mItems[v7];
      if ( *(_DWORD *)(v8 + 8) )
        v10 = *(const char **)v8;
      else
        v10 = &customWorldMapCaption;
      if ( UFG::DUIContext::Slider(v3, v10, v9, *(float *)(v8 + 36), *(float *)(v8 + 40), 0.0) )
        v4->mScalingDirty = 1;
      v7 = (unsigned int)(v7 + 1);
    }
    while ( (unsigned int)v7 < LODWORD(v5[2].mBaseNode.mNeighbours[1]) );
  }
}

// File Line: 515
// RVA: 0x1581F0
void __fastcall UFG::PartCustomizer::BuildUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::PartTemplateInstance *v3; // rdx
  UFG::PartCustomizer *v4; // rdi
  UFG::CompositeBuild *v5; // rax
  UFG::PartCompositeBuilder *v6; // rax

  v2 = dui;
  v3 = this->mInstance;
  v4 = this;
  v5 = UFG::PartCompositeBuilder::sInstance->mProcessingBuild;
  if ( v5 && v5->mDefinition == v3 )
  {
LABEL_15:
    UFG::DUIContext::Label(v2, "Build Pending...");
    return;
  }
  v6 = (UFG::PartCompositeBuilder *)UFG::PartCompositeBuilder::sInstance->mPendingBuilds.mNode.mNext;
  if ( v6 != (UFG::PartCompositeBuilder *)&UFG::PartCompositeBuilder::sInstance->mPendingBuilds )
  {
    while ( (UFG::PartTemplateInstance *)v6->mPendingBuilds.mNode.mPrev != v3 )
    {
      v6 = (UFG::PartCompositeBuilder *)v6->mFreeTargets.p;
      if ( v6 == (UFG::PartCompositeBuilder *)&UFG::PartCompositeBuilder::sInstance->mPendingBuilds )
        goto LABEL_6;
    }
    goto LABEL_15;
  }
LABEL_6:
  if ( UFG::DUIContext::Collapsible(v2, "Part Selection", &this->mCollapseTemplate) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::PartCustomizer::BuildPartSelectionUI(v4, v2);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( !v4->mLoading && !v4->mLoadStatusChanged )
  {
    if ( UFG::DUIContext::Collapsible(v2, "Part Customization", &v4->mCollapseInstance) )
    {
      UFG::DUIContext::BeginIndent(v2);
      UFG::PartCustomizer::BuildPartEditUI(v4, v2);
      UFG::DUIContext::EndIndent(v2);
    }
    if ( UFG::DUIContext::Collapsible(v2, "Scaling Regions", &v4->mCollapseScaling) )
    {
      UFG::DUIContext::BeginIndent(v2);
      UFG::PartCustomizer::BuildScalingUI(v4, v2);
      UFG::DUIContext::EndIndent(v2);
    }
  }
}

// File Line: 549
// RVA: 0x156760
char __fastcall UFG::PartCustomizer::ApplySelectionToInstance(UFG::PartCustomizer *this, UFG::PartCustomizer::PartSelection *selection, UFG::PartTemplateInstance::PartEntry *entry)
{
  UFG::PartDefinition *v3; // rsi
  UFG::PartTemplateInstance::PartEntry *v4; // rdi
  unsigned int v5; // ebx
  int v6; // ecx
  UFG::qSymbolUC *v7; // rcx
  unsigned __int64 v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // edx
  UFG::PartDefinition::CompositeData *v12; // rbp
  unsigned int v13; // ecx
  UFG::PartDefinition::TextureAlternate *v14; // rax

  v3 = selection->mPart;
  v4 = entry;
  v5 = UFG::gNullQSymbolUC.mUID;
  if ( v3 )
  {
    v6 = selection->mTextureSetSelectionIndex;
    v7 = v6 <= 0 ? &UFG::gNullQSymbolUC : &v3->mTextureAlternates.mData.mItems[v6 - 1];
    v5 = v7->mUID;
    if ( (UFG::PartDefinition *)entry->mPart.mData == v3
      && entry->mTextureSet.mUID == v5
      && entry->mDiffuseColours.mData.mNumItems == v3->mCompositeData.mDiffuseChannelDefaults.mData.mNumItems
      && entry->mSpecularValues.mData.mNumItems == v3->mCompositeData.mSpecularChannelDefaults.mData.mNumItems )
    {
      return 0;
    }
  }
  entry->mTextureSet = UFG::gNullQSymbolUC;
  UFG::OnUnloadHandle((char *)entry);
  v9 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v4->mPart.mNameUID = -1i64;
  v4->mPart.mTypeUID = v9;
  v4->mTextureSet.mUID = v5;
  if ( !(v4->mDiffuseColours.mData.mFlags & 2) )
    operator delete[](v4->mDiffuseColours.mData.mItems);
  v10 = 0;
  v4->mDiffuseColours.mData.mItems = 0i64;
  *(_QWORD *)&v4->mDiffuseColours.mData.mNumItems = 0i64;
  if ( !(v4->mSpecularValues.mData.mFlags & 2) )
    operator delete[](v4->mSpecularValues.mData.mItems);
  v4->mSpecularValues.mData.mItems = 0i64;
  *(_QWORD *)&v4->mSpecularValues.mData.mNumItems = 0i64;
  if ( v3 )
  {
    UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v4->mPart.mPrev, v4->mPart.mTypeUID, v3->mBaseNode.mUID);
    v11 = v4->mTextureSet.mUID;
    v12 = &v3->mCompositeData;
    if ( v11 != UFG::gNullQSymbolUC.mUID )
    {
      v13 = v3->mTextureAlternates.mData.mNumItems;
      if ( v13 )
      {
        v14 = v3->mTextureAlternates.mData.mItems;
        while ( v14->mId.mUID != v11 )
        {
          ++v10;
          ++v14;
          if ( v10 >= v13 )
            goto LABEL_22;
        }
        v12 = &v14->mCompositeData;
      }
    }
LABEL_22:
    UFG::PartTemplateInstance::PartEntry::AssignDefaultDiffuseValues(v4, v12);
    UFG::PartTemplateInstance::PartEntry::AssignDefaultSpecularValues(v4, v12);
  }
  return 1;
}

// File Line: 595
// RVA: 0x156450
void __fastcall UFG::PartCustomizer::ApplyCustomization(UFG::PartCustomizer *this)
{
  UFG::PartCustomizer *v1; // r15
  UFG::PartTemplateInstance *v2; // rcx
  UFG::PartTemplateInstance *v3; // rdx
  signed __int64 v4; // rbx
  char v5; // r12
  int v6; // ecx
  UFG::PartCustomizer *v7; // rax
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v8; // rax
  unsigned int i; // edx
  int j; // edx
  int v11; // ecx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *k; // rax
  int v13; // ecx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *l; // rax
  UFG::PartTemplateInstance *v15; // rsi
  UFG::PartTemplateInstance::SlotEntry *v16; // rcx
  char *v17; // rdi
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v18; // rax
  unsigned int m; // edx
  int n; // er14
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *v21; // rdi
  int v22; // ecx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *ii; // rax
  UFG::PartTemplateInstance *v24; // rax
  signed __int64 v25; // rsi
  int jj; // eax
  bool v27; // al
  unsigned int v28; // edx
  __int64 v29; // rbp
  bool v30; // al

  v1 = this;
  v2 = this->mInstance;
  if ( v2 )
  {
    UFG::qReflectHandleBase::Init(
      (UFG::qReflectHandleBase *)&v2->mTemplate.mPrev,
      v2->mTemplate.mTypeUID,
      v1->mPartTemplate->mBaseNode.mUID);
    v3 = v1->mInstance;
    v4 = (signed __int64)&v1->mSelectedParts;
    v5 = 0;
    v6 = 0;
    v7 = (UFG::PartCustomizer *)v1->mSelectedParts.mNode.mNext;
    if ( v7 != (UFG::PartCustomizer *)&v1->mSelectedParts )
    {
      do
      {
        v7 = (UFG::PartCustomizer *)v7->mBaseNode.mUID;
        ++v6;
      }
      while ( v7 != (UFG::PartCustomizer *)v4 );
    }
    if ( v3->mSlots.mData.mNumItems != v6 )
    {
      UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::~qReflectArray<UFG::PartTemplateInstance::SlotEntry>(&v3->mSlots);
      v8 = v1->mSelectedParts.mNode.mNext;
      for ( i = 0;
            v8 != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4;
            ++i )
      {
        v8 = v8->mNext;
      }
      UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::Resize(
        &v1->mInstance->mSlots,
        i,
        "qReflectArray.Resize");
      v5 = 1;
    }
    for ( j = 0; ; ++j )
    {
      v11 = 0;
      for ( k = v1->mSelectedParts.mNode.mNext;
            k != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4;
            ++v11 )
      {
        k = k->mNext;
      }
      if ( j >= v11 )
        break;
      v13 = j;
      for ( l = v1->mSelectedParts.mNode.mNext; v13 > 0; --v13 )
      {
        if ( l == (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4 )
          break;
        l = l->mNext;
      }
      if ( v1->mInstance->mSlots.mData.mItems[j].mSlotName.mUID != HIDWORD(l[1].mPrev) )
      {
        v15 = v1->mInstance;
        if ( !(v15->mSlots.mData.mFlags & 2) )
        {
          v16 = v15->mSlots.mData.mItems;
          if ( v16 )
          {
            v17 = (char *)&v16[-1].mLayers.mData.mNumItems;
            `eh vector destructor iterator(
              v16,
              0x68ui64,
              v16[-1].mLayers.mData.mNumItems,
              (void (__fastcall *)(void *))UFG::PartTemplateInstance::SlotEntry::~SlotEntry);
            operator delete[](v17);
          }
        }
        v15->mSlots.mData.mItems = 0i64;
        *(_QWORD *)&v15->mSlots.mData.mNumItems = 0i64;
        v18 = v1->mSelectedParts.mNode.mNext;
        for ( m = 0;
              v18 != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4;
              ++m )
        {
          v18 = v18->mNext;
        }
        UFG::qReflectArray<UFG::PartTemplateInstance::SlotEntry>::Resize(
          &v1->mInstance->mSlots,
          m,
          "qReflectArray.Resize");
        v5 = 1;
        break;
      }
    }
    for ( n = 0; ; ++n )
    {
      v21 = v1->mSelectedParts.mNode.mNext;
      v22 = 0;
      for ( ii = v21;
            ii != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4;
            ++v22 )
      {
        ii = ii->mNext;
      }
      v24 = v1->mInstance;
      if ( n >= v22 )
        break;
      v25 = (signed __int64)&v24->mSlots.mData.mItems[n];
      for ( jj = n; jj > 0; --jj )
      {
        if ( v21 == (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)v4 )
          break;
        v21 = v21->mNext;
      }
      v27 = UFG::PartCustomizer::ApplySelectionToInstance(
              v1,
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
      v29 = 0i64;
      if ( LODWORD(v21[2].mNext) )
      {
        do
        {
          v30 = UFG::PartCustomizer::ApplySelectionToInstance(
                  v1,
                  (UFG::PartCustomizer::PartSelection *)&v21[3].mPrev[(unsigned int)v29],
                  (UFG::PartTemplateInstance::PartEntry *)(*(_QWORD *)(v25 + 88) + 80 * v29));
          v29 = (unsigned int)(v29 + 1);
          v5 |= v30;
        }
        while ( (unsigned int)v29 < LODWORD(v21[2].mNext) );
      }
    }
    v24->mCompositeDirty = 1;
    UFG::PartCustomizer::sSaveInstanceData(v1->mSimObject, v1->mInstance);
    UFG::PartCustomizer::sConfigureParts(v1->mSimObject, v1->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(v1->mSimObject, v1->mInstance);
    UFG::PartCustomizer::sQueueCompositeBuild(v1->mSimObject, v5, v1->mInstance);
  }
}

// File Line: 660
// RVA: 0x15B6C0
void __fastcall UFG::PartCustomizer::UpdateUI(UFG::PartCustomizer *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::PartCustomizer *v3; // rdi
  signed __int64 v4; // rbx
  UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *i; // r9
  UFG::PartDefinition *v6; // r8
  int v7; // eax
  UFG::qSymbolUC *v8; // rdx
  unsigned int j; // er8
  signed __int64 v10; // rax
  UFG::PartDefinition *v11; // r10
  int v12; // eax
  UFG::qSymbolUC *v13; // rdx
  unsigned int v14; // edx
  unsigned int v15; // er11
  signed __int64 v16; // rcx

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  UFG::PartCustomizer::BuildUI(v3, v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  if ( v3->mLoadStatusChanged )
  {
    v4 = (signed __int64)&v3->mPartLoader;
    UFG::PartLoader::Unload(&v3->mPartLoader);
    v3->mPartLoader.mPartCount = 0;
    for ( i = v3->mSelectedParts.mNode.mNext;
          i != (UFG::qNode<UFG::PartCustomizer::PartSelectionHelper,UFG::PartCustomizer::PartSelectionHelper> *)&v3->mSelectedParts;
          i = i->mNext )
    {
      v6 = (UFG::PartDefinition *)i[2].mPrev;
      if ( v6 )
      {
        v7 = HIDWORD(i[1].mNext);
        if ( v7 <= 0 )
          v8 = &UFG::gNullQSymbolUC;
        else
          v8 = &v6->mTextureAlternates.mData.mItems[v7 - 1].mId;
        v3->mPartLoader.mParts[v3->mPartLoader.mPartCount] = v6;
        *(UFG::qSymbolUC *)(v4 + 4i64 * v3->mPartLoader.mPartCount++ + 272) = (UFG::qSymbolUC)v8->mUID;
      }
      for ( j = 0; j < LODWORD(i[2].mNext); ++j )
      {
        v10 = (signed __int64)&i[3].mPrev[j];
        v11 = *(UFG::PartDefinition **)(v10 + 8);
        if ( v11 )
        {
          v12 = *(_DWORD *)(v10 + 4);
          if ( v12 <= 0 )
            v13 = &UFG::gNullQSymbolUC;
          else
            v13 = &v11->mTextureAlternates.mData.mItems[v12 - 1].mId;
          v3->mPartLoader.mParts[v3->mPartLoader.mPartCount] = v11;
          *(UFG::qSymbolUC *)(v4 + 4i64 * v3->mPartLoader.mPartCount++ + 272) = (UFG::qSymbolUC)v13->mUID;
        }
      }
    }
    UFG::PartLoader::QueueLoad(&v3->mPartLoader);
    *(_WORD *)&v3->mLoadStatusChanged = 256;
    return;
  }
  if ( v3->mLoading )
  {
    v14 = v3->mPartLoader.mPartRequestCount;
    if ( v14 )
    {
      v15 = 0;
      if ( !v14 )
      {
LABEL_25:
        UFG::PartCustomizer::ApplyCustomization(v3);
        v3->mLoading = 0;
        return;
      }
      v16 = (signed __int64)v3->mPartLoader.mPartRequests;
      while ( *(_DWORD *)(*(_QWORD *)v16 + 80i64) == 3 )
      {
        ++v15;
        v16 += 8i64;
        if ( v15 >= v14 )
        {
          UFG::PartCustomizer::ApplyCustomization(v3);
          v3->mLoading = 0;
          return;
        }
      }
    }
    if ( v3->mPartLoader.mPartCount )
      return;
    goto LABEL_25;
  }
  if ( v3->mCompositeDirty )
  {
    v3->mInstance->mCompositeDirty = 1;
    UFG::PartCustomizer::sSaveInstanceData(v3->mSimObject, v3->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(v3->mSimObject, v3->mInstance);
    UFG::PartCustomizer::sQueueCompositeBuild(v3->mSimObject, 0, v3->mInstance);
    v3->mCompositeDirty = 0;
  }
  else if ( v3->mScalingDirty )
  {
    UFG::PartCustomizer::sSaveInstanceData(v3->mSimObject, v3->mInstance);
    UFG::PartCustomizer::sUpdateCustomizationData(v3->mSimObject, v3->mInstance);
    v3->mScalingDirty = 1;
  }
}

