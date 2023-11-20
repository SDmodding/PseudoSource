// File Line: 55
// RVA: 0x1554DD0
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_nisSubtitleList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_nisSubtitleList__);
}

// File Line: 56
// RVA: 0x1554E90
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_subtitleSets__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_subtitleSets__);
}

// File Line: 57
// RVA: 0x1554EA0
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot__);
}

// File Line: 199
// RVA: 0x155CCE0
__int64 UFG::_dynamic_initializer_for__sNISSubtitlesPropSet__()
{
  UFG::qSymbol::create_from_string(&UFG::sNISSubtitlesPropSet, "Audio-Subtitles-NIS");
  return atexit(UFG::_dynamic_atexit_destructor_for__sNISSubtitlesPropSet__);
}

// File Line: 202
// RVA: 0x5A0810
char __fastcall UFG::SubtitleManager::LabelIsCantonese(unsigned int uid)
{
  unsigned int v1; // esi
  UFG::qPropertySet *v2; // rax
  UFG::qPropertyList *v3; // rbp
  unsigned int v4; // edi
  unsigned int v5; // ebx
  UFG::qSymbol *v6; // rax

  v1 = uid;
  if ( _S45_0 & 1 )
  {
    v2 = prop_set;
  }
  else
  {
    _S45_0 |= 1u;
    v2 = UFG::PropertySetManager::FindPropertySet(&UFG::sNISSubtitlesPropSet);
    prop_set = v2;
  }
  if ( !v2 )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&TiDoSym_CantoTags.mUID, DEPTH_RECURSE);
  v4 = v3->mNumElements;
  v5 = 0;
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v6 = UFG::qPropertyList::Get<UFG::qSymbol>(v3, v5);
    if ( v6 )
    {
      if ( v6->mUID == v1 )
        break;
    }
    if ( ++v5 >= v4 )
      return 0;
  }
  return 1;
}

// File Line: 365
// RVA: 0x5A1560
void UFG::SubtitleManager::LoadManifest(void)
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // r12
  SimpleXML::XMLNode *v2; // r13
  char *v3; // rax
  SimpleXML::XMLNode *v4; // r15
  char *v5; // rbx
  unsigned int v6; // eax
  __int64 v7; // rbp
  unsigned int v8; // edi
  unsigned int v9; // er14
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  unsigned int *v13; // r9
  unsigned int *v14; // rsi
  signed __int64 v15; // r8
  signed __int64 v16; // rdx
  unsigned int v17; // eax
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  unsigned int *v22; // r9
  signed __int64 v23; // r8
  signed __int64 v24; // rdx
  SimpleXML::XMLNode *i; // [rsp+50h] [rbp+8h]

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\Manifest.xml", 1ui64, 0i64);
  v1 = v0;
  if ( v0 )
  {
    v2 = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
    for ( i = v2; v2; i = v2 )
    {
      v3 = SimpleXML::XMLNode::GetName(v2);
      UFG::qPrintf("found node %s\n", v3);
      v4 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, v2);
      SimpleXML::XMLNode::GetChildCount(v2);
      if ( UFG::SubtitleManager::sm_subtitleSets.p )
        operator delete[](UFG::SubtitleManager::sm_subtitleSets.p);
      UFG::SubtitleManager::sm_subtitleSets.p = 0i64;
      *(_QWORD *)&UFG::SubtitleManager::sm_subtitleSets.size = 0i64;
      if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p )
        operator delete[](UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p);
      UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p = 0i64;
      *(_QWORD *)&UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size = 0i64;
      if ( v4 )
      {
        do
        {
          v5 = SimpleXML::XMLNode::GetAttribute(v4, "name", &customWorldMapCaption);
          if ( SimpleXML::XMLNode::GetAttribute(v4, "loadOnBoot", 0) )
          {
            v6 = UFG::TiDo::CalcWwiseUid(v5);
            v7 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size;
            v8 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size + 1;
            v9 = v6;
            if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size + 1 <= UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity )
              goto LABEL_54;
            if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity )
              v10 = 2 * UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity;
            else
              v10 = 1;
            for ( ; v10 < v8; v10 *= 2 )
              ;
            if ( v10 <= 4 )
              v10 = 4;
            if ( v10 - v8 > 0x10000 )
              v10 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size + 65537;
            if ( v10 == (_DWORD)v7 )
            {
LABEL_54:
              v14 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
              ++UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size;
            }
            else
            {
              v11 = 4i64 * v10;
              if ( !is_mul_ok(v10, 4ui64) )
                v11 = -1i64;
              v12 = UFG::qMalloc(v11, "subtitleMgr", 0i64);
              v13 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
              v14 = (unsigned int *)v12;
              if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p )
              {
                v15 = 0i64;
                if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
                {
                  do
                  {
                    v16 = v15;
                    v15 = (unsigned int)(v15 + 1);
                    *(_DWORD *)((char *)&v12->mNext + v16 * 4) = v13[v16];
                    v13 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
                  }
                  while ( (unsigned int)v15 < UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size );
                }
                operator delete[](v13);
              }
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p = v14;
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity = v10;
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size = v8;
            }
          }
          else
          {
            v17 = UFG::TiDo::CalcWwiseUid(v5);
            v7 = UFG::SubtitleManager::sm_subtitleSets.size;
            v18 = UFG::SubtitleManager::sm_subtitleSets.size + 1;
            v9 = v17;
            if ( UFG::SubtitleManager::sm_subtitleSets.size + 1 <= UFG::SubtitleManager::sm_subtitleSets.capacity )
              goto LABEL_55;
            if ( UFG::SubtitleManager::sm_subtitleSets.capacity )
              v19 = 2 * UFG::SubtitleManager::sm_subtitleSets.capacity;
            else
              v19 = 1;
            for ( ; v19 < v18; v19 *= 2 )
              ;
            if ( v19 <= 4 )
              v19 = 4;
            if ( v19 - v18 > 0x10000 )
              v19 = UFG::SubtitleManager::sm_subtitleSets.size + 65537;
            if ( v19 == (_DWORD)v7 )
            {
LABEL_55:
              v14 = UFG::SubtitleManager::sm_subtitleSets.p;
            }
            else
            {
              v20 = 4i64 * v19;
              if ( !is_mul_ok(v19, 4ui64) )
                v20 = -1i64;
              v21 = UFG::qMalloc(v20, "subtitleMgr", 0i64);
              v22 = UFG::SubtitleManager::sm_subtitleSets.p;
              v14 = (unsigned int *)v21;
              if ( UFG::SubtitleManager::sm_subtitleSets.p )
              {
                v23 = 0i64;
                if ( UFG::SubtitleManager::sm_subtitleSets.size )
                {
                  do
                  {
                    v24 = v23;
                    v23 = (unsigned int)(v23 + 1);
                    *(_DWORD *)((char *)&v21->mNext + v24 * 4) = v22[v24];
                    v22 = UFG::SubtitleManager::sm_subtitleSets.p;
                  }
                  while ( (unsigned int)v23 < UFG::SubtitleManager::sm_subtitleSets.size );
                }
                operator delete[](v22);
              }
              UFG::SubtitleManager::sm_subtitleSets.p = v14;
              UFG::SubtitleManager::sm_subtitleSets.capacity = v19;
            }
            UFG::SubtitleManager::sm_subtitleSets.size = v18;
          }
          v14[v7] = v9;
          v4 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v4);
        }
        while ( v4 );
        v2 = i;
      }
      v2 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v2);
    }
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
}

// File Line: 451
// RVA: 0x1554BB0
__int64 dynamic_initializer_for__UFG::SubtitleContainer::sm_Map__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SubtitleContainer::sm_Map.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SubtitleContainer::sm_Map__);
}

// File Line: 463
// RVA: 0x599750
UFG::allocator::free_link *__fastcall UFG::SubtitleContainer::Create(__int64 setName)
{
  UFG::qSymbolUC *v1; // rdi
  UFG::allocator::free_link *v2; // rsi
  UFG::qPropertySet *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertyList *v5; // r14
  unsigned int v6; // ebx
  char *v7; // rax
  UFG::qSymbolUC v9; // ebx
  char *v10; // rax
  unsigned int v11; // er15
  unsigned int v12; // ebp
  char *v13; // rax
  UFG::qPropertySet *v14; // rbx
  char *v15; // rdi
  char *v16; // rbx
  unsigned int v17; // eax

  v1 = (UFG::qSymbolUC *)setName;
  v2 = 0i64;
  v3 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)setName);
  if ( v3 )
  {
    v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x38ui64, "SubtitleContainer", 0i64, 1u);
    v2 = v4;
    if ( v4 )
    {
      v4[1].mNext = 0i64;
      v4[2].mNext = 0i64;
      v4[3].mNext = 0i64;
      v4->mNext = (UFG::allocator::free_link *)&UFG::SubtitleContainer::`vftable;
      LODWORD(v4[6].mNext) = 1;
    }
    else
    {
      v2 = 0i64;
    }
    LODWORD(v2[4].mNext) = (UFG::qSymbolUC)v1->mUID;
    v2[5].mNext = (UFG::allocator::free_link *)v3;
    if ( UFG::SubtitleManager::sm_debugSubtitles )
    {
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&TiDoSym_Subtitles.mUID, DEPTH_RECURSE);
      if ( !v5 )
      {
        v6 = v1->mUID;
        v7 = UFG::qSymbol::as_cstr_dbg(v1);
        UFG::qPrintf("Subtitle set not found for: %u : %s \n", v6, v7);
        return 0i64;
      }
      if ( UFG::SubtitleManager::sm_debugSubtitles )
      {
        v9.mUID = v1->mUID;
        v10 = UFG::qSymbol::as_cstr_dbg(v1);
        UFG::qPrintf("Subtitle set loaded from : %u : %s \n", v9.mUID, v10);
      }
      v11 = v5->mNumElements;
      v12 = 0;
      if ( v11 )
      {
        do
        {
          v13 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v12);
          if ( v13 && *(_QWORD *)v13 )
            v14 = (UFG::qPropertySet *)&v13[*(_QWORD *)v13];
          else
            v14 = 0i64;
          v15 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&TiDoSym_SampleName.mUID, DEPTH_RECURSE);
          v16 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qSymbol *)&TiDoSym_Text.mUID, DEPTH_RECURSE);
          v17 = UFG::qStringHashUpper32(v15, 0xFFFFFFFF);
          UFG::qPrintf("Subtitle Loaded: %s : %u :%s \n", v15, v17, v16);
          ++v12;
        }
        while ( v12 < v11 );
      }
    }
  }
  return v2;
}

// File Line: 518
// RVA: 0x59DD10
UFG::allocator::free_link *__fastcall UFG::SubtitleContainer::GrabParametersInstance(__int64 setName)
{
  unsigned int *v1; // rbx
  UFG::qBaseTreeRB *v2; // rax
  UFG::allocator::free_link *result; // rax
  UFG::SubtitleContainer *v4; // rbx
  UFG::qSymbol setNamea; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v6; // [rsp+48h] [rbp+10h]

  v1 = (unsigned int *)setName;
  if ( *(_DWORD *)setName
    && (v2 = UFG::qBaseTreeRB::Get(&UFG::SubtitleContainer::sm_Map.mTree, *(_DWORD *)setName)) != 0i64
    && (result = (UFG::allocator::free_link *)&v2[-1].mCount) != 0i64 )
  {
    ++LODWORD(result[6].mNext);
  }
  else
  {
    v6 = &setNamea;
    setNamea.mUID = *v1;
    result = UFG::SubtitleContainer::Create((__int64)&setNamea);
    v4 = (UFG::SubtitleContainer *)result;
    if ( result )
    {
      UFG::qBaseTreeRB::Add(&UFG::SubtitleContainer::sm_Map.mTree, (UFG::qBaseNodeRB *)&result[1]);
      result = (UFG::allocator::free_link *)v4;
    }
  }
  return result;
}

// File Line: 574
// RVA: 0x5AB2B0
void __fastcall UFG::SubtitleManager::SetSubtitleMode(UFG::SubtitleManager::eSubtitleMode mode)
{
  UFG::SubtitleManager::sm_subtitleMode = mode;
}

