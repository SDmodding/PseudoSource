// File Line: 40
// RVA: 0x145AE90
__int64 UFG::_dynamic_initializer_for__UIBlipSymbol_caption__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("caption", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UIBlipSymbol_caption, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__UIBlipSymbol_caption__);
}

// File Line: 58
// RVA: 0xCEFE0
UFG::UIMapBlipTypeManager *__fastcall UFG::UIMapBlipTypeManager::getInstance()
{
  UFG::UIMapBlipTypeManager *result; // rax
  UFG::UIMapBlipTypeManager *v1; // rax

  result = sUIMapBlipTypeManager;
  if ( !sUIMapBlipTypeManager )
  {
    v1 = (UFG::UIMapBlipTypeManager *)UFG::qMemoryPool::Allocate(
                                        &gScaleformMemoryPool,
                                        (unsigned int)((_DWORD)sUIMapBlipTypeManager + 32),
                                        "UIMapBlipTypeManager",
                                        0i64,
                                        1u);
    if ( v1 )
    {
      v1->mData.p = 0i64;
      *(_QWORD *)&v1->mData.size = 0i64;
      v1->mNumTypes = 0;
      v1->mPSSetData = 0i64;
    }
    else
    {
      v1 = 0i64;
    }
    sUIMapBlipTypeManager = v1;
    UFG::UIMapBlipTypeManager::Init(v1);
    return sUIMapBlipTypeManager;
  }
  return result;
}

// File Line: 71
// RVA: 0xCEF00
bool __fastcall UFG::fnSortBlipTypeSets(UFG::qPropertySet **a, UFG::qPropertySet **b)
{
  char *v3; // rbx
  char *v4; // rdi

  v3 = PropertyUtils::Get<char const *>(*a, &UIBlipSymbol_typeName, DEPTH_RECURSE);
  v4 = PropertyUtils::Get<char const *>(*b, &UIBlipSymbol_typeName, DEPTH_RECURSE);
  LODWORD(v3) = UFG::qStringHashUpper32(v3, 0xFFFFFFFF);
  return (unsigned int)v3 < (unsigned int)UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
}

// File Line: 82
// RVA: 0xC5210
void __fastcall UFG::UIMapBlipTypeManager::Init(UFG::UIMapBlipTypeManager *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // rax
  unsigned int mNumElements; // edi
  unsigned int size; // edx
  unsigned int capacity; // edx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  char *v10; // r15
  unsigned int v11; // esi
  unsigned int v12; // r12d
  unsigned int v13; // r13d
  UFG::qPropertyList *v14; // r14
  char *ValuePtr; // rax
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned int v18; // ebx
  unsigned __int64 v19; // rax
  char *v20; // rax
  __int64 v21; // r12
  _QWORD *v22; // rdx
  __int64 v23; // r8
  __int64 v24; // rsi
  UFG::qPropertySet *v25; // rbx
  bool *v26; // rax
  char *v27; // rcx
  bool *v28; // rax
  UFG::qSymbol *v29; // rcx
  bool *v30; // rax
  unsigned int *v31; // rcx
  bool *v32; // rax
  __int64 *v33; // rcx
  float *v34; // rax
  float *v35; // rcx
  float v36; // xmm7_4
  unsigned int *v37; // rax
  int *v38; // rcx
  unsigned int v39; // r12d
  unsigned int *v40; // rax
  int *v41; // rcx
  unsigned int v42; // r13d
  bool *v43; // rax
  char *v44; // rcx
  bool *v45; // rax
  char *v46; // rcx
  bool *v47; // rax
  bool *v48; // rcx
  float *v49; // rax
  float *v50; // rcx
  float v51; // xmm8_4
  bool *v52; // rax
  char *v53; // rdx
  bool *v54; // rax
  char *v55; // rdx
  UFG::qSymbol *v56; // rax
  unsigned int v57; // ebx
  UFG::UIHKMinimapBlipType *p; // rdi
  __int64 v59; // rdi
  UFG::UIHKMinimapBlipType *v60; // rcx
  UFG::UIHKMinimapBlipType *v61; // rcx
  char v62; // [rsp+1h] [rbp-80h] BYREF
  char v63; // [rsp+2h] [rbp-7Fh]
  char v64; // [rsp+3h] [rbp-7Eh]
  char v65; // [rsp+4h] [rbp-7Dh] BYREF
  char v66; // [rsp+5h] [rbp-7Ch] BYREF
  __int64 v67; // [rsp+8h] [rbp-79h]
  char *v68; // [rsp+10h] [rbp-71h]
  float v69; // [rsp+18h] [rbp-69h] BYREF
  float v70; // [rsp+1Ch] [rbp-65h] BYREF
  int v71[3]; // [rsp+20h] [rbp-61h] BYREF
  int v72; // [rsp+2Ch] [rbp-55h] BYREF
  __int64 v73; // [rsp+30h] [rbp-51h]
  UFG::qSymbolUC v74; // [rsp+38h] [rbp-49h] BYREF
  char v75; // [rsp+3Ch] [rbp-45h]
  char v76; // [rsp+3Dh] [rbp-44h] BYREF
  char v77; // [rsp+3Eh] [rbp-43h]
  char mUID; // [rsp+3Fh] [rbp-42h]
  __int64 v79; // [rsp+40h] [rbp-41h]
  UFG::qSymbol *v80; // [rsp+48h] [rbp-39h]
  char *pszSymbolString; // [rsp+50h] [rbp-31h]
  char *text; // [rsp+58h] [rbp-29h]
  __int64 v83; // [rsp+60h] [rbp-21h]
  UFG::UIMapBlipTypeManager *v84; // [rsp+E8h] [rbp+67h] BYREF
  UFG::qSymbol result[2]; // [rsp+F0h] [rbp+6Fh] BYREF
  unsigned int v86; // [rsp+F8h] [rbp+77h] BYREF
  char *v87; // [rsp+100h] [rbp+7Fh] BYREF
  UFG::qSymbol v88; // [rsp+130h] [rbp+AFh] BYREF

  v83 = -2i64;
  v2 = UFG::qSymbol::create_from_string(&v88, "UI-MinimapBlipTypes");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  this->mPSSetData = PropertySet;
  if ( PropertySet )
  {
    v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &UIBlipSymbol_blipTypes, DEPTH_RECURSE);
    *(_QWORD *)&result[0].mUID = v4;
    if ( v4 )
    {
      mNumElements = v4->mNumElements;
      v86 = mNumElements;
      size = this->mData.size;
      if ( (int)(mNumElements - this->mData.size) <= 0 )
      {
        v9 = this->mData.size - mNumElements;
        if ( v9 )
        {
          if ( v9 < size )
            this->mData.size = size - v9;
          else
            this->mData.size = 0;
        }
      }
      else
      {
        capacity = this->mData.capacity;
        if ( mNumElements > capacity )
        {
          if ( capacity )
            v8 = 2 * capacity;
          else
            v8 = 1;
          for ( ; v8 < mNumElements; v8 *= 2 )
            ;
          if ( v8 - mNumElements > 0x10000 )
            v8 = mNumElements + 0x10000;
          UFG::qArray<UFG::UIHKMinimapBlipType,0>::Reallocate(&this->mData, v8, "UIMapBlipTypeManager");
        }
        this->mData.size = mNumElements;
      }
      this->mNumTypes = mNumElements;
      v10 = 0i64;
      v68 = 0i64;
      v11 = 0;
      v67 = 0i64;
      v12 = 0;
      v13 = 0;
      if ( mNumElements )
      {
        v14 = *(UFG::qPropertyList **)&result[0].mUID;
        do
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v13);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v87 = &ValuePtr[*(_QWORD *)ValuePtr];
          else
            v87 = 0i64;
          v16 = v11;
          v17 = v11 + 1;
          if ( v11 + 1 > v12 )
          {
            v18 = 1;
            if ( v12 )
              v18 = 2 * v12;
            for ( ; v18 < v17; v18 *= 2 )
              ;
            if ( v18 <= 2 )
              v18 = 2;
            if ( v18 - v17 > 0x10000 )
              v18 = v11 + 65537;
            if ( v18 != v11 )
            {
              v19 = 8i64 * v18;
              if ( !is_mul_ok(v18, 8ui64) )
                v19 = -1i64;
              v20 = UFG::qMalloc(v19, "qArray.Add", 0i64);
              v21 = (__int64)v20;
              if ( v10 )
              {
                if ( v11 )
                {
                  v22 = v20;
                  v23 = v11;
                  do
                  {
                    *v22 = *(_QWORD *)((char *)v22 + v10 - v20);
                    ++v22;
                    --v23;
                  }
                  while ( v23 );
                }
                operator delete[](v10);
              }
              v10 = (char *)v21;
              v68 = (char *)v21;
              v12 = v18;
              HIDWORD(v67) = v18;
              v16 = v11;
            }
          }
          ++v11;
          LODWORD(v67) = v17;
          *(_QWORD *)&v10[8 * v16] = v87;
          ++v13;
          mNumElements = v86;
        }
        while ( v13 < v86 );
        this = v84;
      }
      UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
        (UFG::qPropertySet **)v10,
        (UFG::qPropertySet **)&v10[8 * v11 - 8],
        UFG::fnSortBlipTypeSets);
      if ( mNumElements )
      {
        LOBYTE(v84) = 0;
        LOBYTE(result[0].mUID) = 0;
        LOBYTE(v86) = 1;
        LOBYTE(v87) = 0;
        v69 = FLOAT_150_0;
        v71[0] = 0;
        v72 = 0;
        v71[2] = 0;
        v66 = 0;
        v65 = 1;
        HIBYTE(v74.mUID) = 0;
        v70 = FLOAT_0_80000001;
        v62 = 0;
        v76 = 0;
        v24 = 0i64;
        v73 = 0i64;
        v79 = mNumElements;
        do
        {
          v25 = *(UFG::qPropertySet **)v10;
          pszSymbolString = PropertyUtils::Get<char const *>(
                              *(UFG::qPropertySet **)v10,
                              &UIBlipSymbol_typeName,
                              DEPTH_RECURSE);
          v80 = UFG::qPropertySet::Get<UFG::qSymbol>(v25, &UIBlipSymbol_icon, DEPTH_RECURSE);
          text = UFG::qPropertySet::Get<char const *>(v25, &UIBlipSymbol_caption, DEPTH_RECURSE);
          v26 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isWorldMapOnly, DEPTH_RECURSE);
          v27 = (char *)&v84;
          if ( v26 )
            v27 = (char *)v26;
          v64 = *v27;
          v28 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isObjective, DEPTH_RECURSE);
          v29 = result;
          if ( v28 )
            v29 = (UFG::qSymbol *)v28;
          mUID = v29->mUID;
          v30 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isDistanceFiltered, DEPTH_RECURSE);
          v31 = &v86;
          if ( v30 )
            v31 = (unsigned int *)v30;
          BYTE1(v74.mUID) = *(_BYTE *)v31;
          v32 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isDistanceFilteredOnWorldMap, DEPTH_RECURSE);
          v33 = (__int64 *)&v87;
          if ( v32 )
            v33 = (__int64 *)v32;
          BYTE2(v74.mUID) = *(_BYTE *)v33;
          v34 = UFG::qPropertySet::Get<float>(v25, &UIBlipSymbol_filterDistance, DEPTH_RECURSE);
          v35 = &v69;
          if ( v34 )
            v35 = v34;
          v36 = *v35;
          v37 = UFG::qPropertySet::Get<unsigned long>(v25, &UIBlipSymbol_radiusColor, DEPTH_RECURSE);
          v38 = v71;
          if ( v37 )
            v38 = (int *)v37;
          v39 = *v38;
          v40 = UFG::qPropertySet::Get<unsigned long>(v25, &UIBlipSymbol_innerRadiusColor, DEPTH_RECURSE);
          v41 = &v72;
          if ( v40 )
            v41 = (int *)v40;
          v42 = *v41;
          UFG::qPropertySet::Get<unsigned long>(v25, &UIBlipSymbol_drawDepth, DEPTH_RECURSE);
          v43 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isHiddenIndoors, DEPTH_RECURSE);
          v44 = &v66;
          if ( v43 )
            v44 = (char *)v43;
          v75 = *v44;
          v45 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_hasAltitude, DEPTH_RECURSE);
          v46 = &v65;
          if ( v45 )
            v46 = (char *)v45;
          v77 = *v46;
          v47 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isWorldMapZoomFiltered, DEPTH_RECURSE);
          v48 = (bool *)&v74.mUID + 3;
          if ( v47 )
            v48 = v47;
          LOBYTE(v79) = *v48;
          v49 = UFG::qPropertySet::Get<float>(v25, &UIBlipSymbol_worldMapZoomFilter, DEPTH_RECURSE);
          v50 = &v70;
          if ( v49 )
            v50 = v49;
          v51 = *v50;
          v52 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_isProximityUnlockable, DEPTH_RECURSE);
          v53 = &v62;
          if ( v52 )
            v53 = (char *)v52;
          v63 = *v53;
          v54 = UFG::qPropertySet::Get<bool>(v25, &UIBlipSymbol_hideOnBorder, DEPTH_RECURSE);
          v55 = &v76;
          if ( v54 )
            v55 = (char *)v54;
          LOBYTE(v74.mUID) = *v55;
          v56 = UFG::qPropertySet::Get<UFG::qSymbol>(v25, &UIBlipSymbol_progressionFlow, DEPTH_RECURSE);
          if ( v56 )
            v57 = v56->mUID;
          else
            v57 = qSymbol_none.mUID;
          p = this->mData.p;
          p[v24].TypeNameSymbol = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&v74, pszSymbolString)->mUID;
          this->mData.p[v24].Icon = (UFG::qSymbol)v80->mUID;
          v59 = v73;
          UFG::qString::Set((UFG::qString *)((char *)&this->mData.p->Caption + v73), text);
          this->mData.p[v24].IsWorldMapOnly = v64;
          this->mData.p[v24].IsObjective = mUID;
          *(_WORD *)&this->mData.p[v24].IsDistanceFiltered = *(_WORD *)((char *)&v74.mUID + 1);
          this->mData.p[v24].FilterDistance = v36;
          v60 = this->mData.p;
          v60[v24].RadiusColor.r = (float)HIBYTE(v39) * 0.0039215689;
          v60[v24].RadiusColor.g = (float)BYTE2(v39) * 0.0039215689;
          v60[v24].RadiusColor.b = (float)BYTE1(v39) * 0.0039215689;
          v60[v24].RadiusColor.a = (float)(unsigned __int8)v39 * 0.0039215689;
          v61 = this->mData.p;
          v61[v24].InnerRadiusColor.r = (float)HIBYTE(v42) * 0.0039215689;
          v61[v24].InnerRadiusColor.g = (float)BYTE2(v42) * 0.0039215689;
          v61[v24].InnerRadiusColor.b = (float)BYTE1(v42) * 0.0039215689;
          v61[v24].InnerRadiusColor.a = (float)(unsigned __int8)v42 * 0.0039215689;
          this->mData.p[v24].DrawDepth = v71[1];
          this->mData.p[v24].IsHiddenIndoors = v75;
          this->mData.p[v24].HasAltitude = v77;
          this->mData.p[v24].IsWorldMapZoomFiltered = v79;
          this->mData.p[v24].WorldMapZoomFilter = v51;
          this->mData.p[v24].IsProximityUnlockable = v63;
          this->mData.p[v24].HideOnBorder = v74.mUID;
          this->mData.p[v24].ProgressionFlow.mUID = v57;
          v73 = v59 + 112;
          v10 += 8;
          ++v24;
          --v79;
        }
        while ( v79 );
        v10 = v68;
      }
      if ( v10 )
        operator delete[](v10);
    }
  }
}    v10 = v68;
      }
      if ( v10 )
        operator delete[](v10);
    }
  }
}

// File Line: 197
// RVA: 0xC4A90
UFG::UIHKMinimapBlipType *__fastcall UFG::UIMapBlipTypeManager::GetType(
        UFG::UIMapBlipTypeManager *this,
        UFG::qSymbolUC *typeName)
{
  unsigned int mUID; // r10d
  unsigned int mNumTypes; // r8d
  __int64 v5; // r11
  UFG::UIHKMinimapBlipType *p; // rbx
  unsigned int v7; // edx
  unsigned int v8; // r8d
  int v9; // eax
  unsigned int v10; // r9d

  mUID = typeName->mUID;
  if ( typeName->mUID == -1 )
    return 0i64;
  mNumTypes = this->mNumTypes;
  v5 = 0i64;
  if ( !mNumTypes )
    return (UFG::UIHKMinimapBlipType *)v5;
  p = this->mData.p;
  v7 = 0;
  v8 = mNumTypes - 1;
  while ( 1 )
  {
    v9 = v7 + ((v8 - v7) >> 1);
    v10 = *(unsigned int *)((char *)&p->TypeNameSymbol.mUID + (unsigned int)(112 * v9));
    if ( v10 >= mUID )
      break;
    v7 = v9 + 1;
LABEL_9:
    if ( v7 > v8 )
      return 0i64;
  }
  if ( v10 > mUID )
  {
    v8 = v9 - 1;
    goto LABEL_9;
  }
  return (UFG::UIHKMinimapBlipType *)((char *)p + (unsigned int)(112 * v9));
}

// File Line: 241
// RVA: 0xC5DB0
UFG::UIHKMinimapBlipType *__fastcall UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(
        UFG::qSymbolUC *iconType)
{
  UFG::UIMapBlipTypeManager *Instance; // rax
  UFG::UIHKMinimapBlipType *result; // rax
  UFG::UIHKMinimapBlipType *v4; // rbx
  UFG::ProgressionTracker *v5; // rax

  Instance = UFG::UIMapBlipTypeManager::getInstance();
  result = UFG::UIMapBlipTypeManager::GetType(Instance, iconType);
  v4 = result;
  if ( result )
    result = (UFG::UIHKMinimapBlipType *)(result->ProgressionFlow.mUID == qSymbol_none.mUID
                                       || (v5 = UFG::ProgressionTracker::Instance(),
                                           v4->ProgressionFlow.mUID == UFG::ProgressionTracker::GetActiveFlow(v5)->mUID));
  return result;
}

