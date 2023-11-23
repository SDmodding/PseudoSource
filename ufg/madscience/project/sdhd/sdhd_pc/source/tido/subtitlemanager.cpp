// File Line: 55
// RVA: 0x1554DD0
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_nisSubtitleList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_nisSubtitleList__);
}

// File Line: 56
// RVA: 0x1554E90
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_subtitleSets__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_subtitleSets__);
}

// File Line: 57
// RVA: 0x1554EA0
__int64 dynamic_initializer_for__UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot__);
}

// File Line: 199
// RVA: 0x155CCE0
__int64 UFG::_dynamic_initializer_for__sNISSubtitlesPropSet__()
{
  UFG::qSymbol::create_from_string(&UFG::sNISSubtitlesPropSet, "Audio-Subtitles-NIS");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sNISSubtitlesPropSet__);
}

// File Line: 202
// RVA: 0x5A0810
char __fastcall UFG::SubtitleManager::LabelIsCantonese(unsigned int uid)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v3; // rbp
  unsigned int mNumElements; // edi
  unsigned int v5; // ebx
  UFG::qSymbol *v6; // rax

  if ( (_S45_0 & 1) != 0 )
  {
    PropertySet = prop_set;
  }
  else
  {
    _S45_0 |= 1u;
    PropertySet = UFG::PropertySetManager::FindPropertySet(&UFG::sNISSubtitlesPropSet);
    prop_set = PropertySet;
  }
  if ( !PropertySet )
    return 0;
  v3 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&TiDoSym_CantoTags,
         DEPTH_RECURSE);
  mNumElements = v3->mNumElements;
  v5 = 0;
  if ( !mNumElements )
    return 0;
  while ( 1 )
  {
    v6 = UFG::qPropertyList::Get<UFG::qSymbol>(v3, v5);
    if ( v6 )
    {
      if ( v6->mUID == uid )
        break;
    }
    if ( ++v5 >= mNumElements )
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
  SimpleXML::XMLNode *Node; // r13
  char *Name; // rax
  SimpleXML::XMLNode *ChildNode; // r15
  char *Attribute; // rbx
  unsigned int v6; // eax
  __int64 size; // rbp
  unsigned int v8; // edi
  unsigned int v9; // r14d
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  unsigned int *v13; // r9
  unsigned int *p; // rsi
  __int64 j; // r8
  __int64 v16; // rdx
  unsigned int v17; // eax
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  unsigned int *v22; // r9
  __int64 k; // r8
  __int64 v24; // rdx
  SimpleXML::XMLNode *i; // [rsp+50h] [rbp+8h]

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\Manifest.xml", 1ui64, 0i64);
  v1 = v0;
  if ( v0 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
    for ( i = Node; Node; i = Node )
    {
      Name = SimpleXML::XMLNode::GetName(Node);
      UFG::qPrintf("found node %s\n", Name);
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, Node);
      SimpleXML::XMLNode::GetChildCount(Node);
      if ( UFG::SubtitleManager::sm_subtitleSets.p )
        operator delete[](UFG::SubtitleManager::sm_subtitleSets.p);
      UFG::SubtitleManager::sm_subtitleSets.p = 0i64;
      *(_QWORD *)&UFG::SubtitleManager::sm_subtitleSets.size = 0i64;
      if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p )
        operator delete[](UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p);
      UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p = 0i64;
      *(_QWORD *)&UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size = 0i64;
      if ( ChildNode )
      {
        do
        {
          Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "name", &customCaption);
          if ( SimpleXML::XMLNode::GetAttribute(ChildNode, "loadOnBoot", 0) )
          {
            v6 = UFG::TiDo::CalcWwiseUid(Attribute);
            size = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size;
            v8 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size + 1;
            v9 = v6;
            if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size + 1 <= UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity )
              goto LABEL_27;
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
            if ( v10 == UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size )
            {
LABEL_27:
              p = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
              ++UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size;
            }
            else
            {
              v11 = 4i64 * v10;
              if ( !is_mul_ok(v10, 4ui64) )
                v11 = -1i64;
              v12 = UFG::qMalloc(v11, "subtitleMgr", 0i64);
              v13 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p;
              p = (unsigned int *)v12;
              if ( UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p )
              {
                for ( j = 0i64;
                      (unsigned int)j < UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size;
                      v13 = UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p )
                {
                  v16 = j;
                  j = (unsigned int)(j + 1);
                  *(_DWORD *)((char *)&v12->mNext + v16 * 4) = v13[v16];
                }
                operator delete[](v13);
              }
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.p = p;
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.capacity = v10;
              UFG::SubtitleManager::sm_subtitleSets_LoadOnBoot.size = v8;
            }
          }
          else
          {
            v17 = UFG::TiDo::CalcWwiseUid(Attribute);
            size = UFG::SubtitleManager::sm_subtitleSets.size;
            v18 = UFG::SubtitleManager::sm_subtitleSets.size + 1;
            v9 = v17;
            if ( UFG::SubtitleManager::sm_subtitleSets.size + 1 <= UFG::SubtitleManager::sm_subtitleSets.capacity )
              goto LABEL_46;
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
            if ( v19 == UFG::SubtitleManager::sm_subtitleSets.size )
            {
LABEL_46:
              p = UFG::SubtitleManager::sm_subtitleSets.p;
            }
            else
            {
              v20 = 4i64 * v19;
              if ( !is_mul_ok(v19, 4ui64) )
                v20 = -1i64;
              v21 = UFG::qMalloc(v20, "subtitleMgr", 0i64);
              v22 = UFG::SubtitleManager::sm_subtitleSets.p;
              p = (unsigned int *)v21;
              if ( UFG::SubtitleManager::sm_subtitleSets.p )
              {
                for ( k = 0i64;
                      (unsigned int)k < UFG::SubtitleManager::sm_subtitleSets.size;
                      v22 = UFG::SubtitleManager::sm_subtitleSets.p )
                {
                  v24 = k;
                  k = (unsigned int)(k + 1);
                  *(_DWORD *)((char *)&v21->mNext + v24 * 4) = v22[v24];
                }
                operator delete[](v22);
              }
              UFG::SubtitleManager::sm_subtitleSets.p = p;
              UFG::SubtitleManager::sm_subtitleSets.capacity = v19;
            }
            UFG::SubtitleManager::sm_subtitleSets.size = v18;
          }
          p[size] = v9;
          ChildNode = SimpleXML::XMLDocument::GetNode(v1, 0i64, ChildNode);
        }
        while ( ChildNode );
        Node = i;
      }
      Node = SimpleXML::XMLDocument::GetNode(v1, 0i64, Node);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubtitleContainer::sm_Map__);
}

// File Line: 463
// RVA: 0x599750
UFG::allocator::free_link *__fastcall UFG::SubtitleContainer::Create(UFG::qSymbol *setName)
{
  UFG::allocator::free_link *v2; // rsi
  UFG::qPropertySet *PropertySet; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertyList *v5; // r14
  UFG::qSymbol v6; // ebx
  char *v7; // rax
  UFG::qSymbol v9; // ebx
  char *v10; // rax
  unsigned int mNumElements; // r15d
  unsigned int i; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v14; // rbx
  char *v15; // rdi
  char *v16; // rbx
  unsigned int v17; // eax

  v2 = 0i64;
  PropertySet = UFG::PropertySetManager::FindPropertySet(setName);
  if ( PropertySet )
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
    LODWORD(v2[4].mNext) = (UFG::qSymbol)setName->mUID;
    v2[5].mNext = (UFG::allocator::free_link *)PropertySet;
    if ( UFG::SubtitleManager::sm_debugSubtitles )
    {
      v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
             PropertySet,
             (UFG::qArray<unsigned long,0> *)&TiDoSym_Subtitles,
             DEPTH_RECURSE);
      if ( !v5 )
      {
        v6.mUID = setName->mUID;
        v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)setName);
        UFG::qPrintf("Subtitle set not found for: %u : %s \n", v6.mUID, v7);
        return 0i64;
      }
      if ( UFG::SubtitleManager::sm_debugSubtitles )
      {
        v9.mUID = setName->mUID;
        v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)setName);
        UFG::qPrintf("Subtitle set loaded from : %u : %s \n", v9.mUID, v10);
      }
      mNumElements = v5->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, i);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v14 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v14 = 0i64;
        v15 = UFG::qPropertySet::Get<char const *>(
                v14,
                (UFG::qArray<unsigned long,0> *)&TiDoSym_SampleName,
                DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Get<char const *>(v14, (UFG::qArray<unsigned long,0> *)&TiDoSym_Text, DEPTH_RECURSE);
        v17 = UFG::qStringHashUpper32(v15, -1);
        UFG::qPrintf("Subtitle Loaded: %s : %u :%s \n", v15, v17, v16);
      }
    }
  }
  return v2;
}

// File Line: 518
// RVA: 0x59DD10
UFG::allocator::free_link *__fastcall UFG::SubtitleContainer::GrabParametersInstance(unsigned int *setName)
{
  UFG::qBaseTreeRB *v2; // rax
  UFG::allocator::free_link *result; // rax
  UFG::SubtitleContainer *v4; // rbx
  UFG::qSymbol setNamea; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_setNamea; // [rsp+48h] [rbp+10h]

  if ( *setName
    && (v2 = UFG::qBaseTreeRB::Get(&UFG::SubtitleContainer::sm_Map.mTree, *setName)) != 0i64
    && (result = (UFG::allocator::free_link *)&v2[-1].mCount) != 0i64 )
  {
    ++LODWORD(result[6].mNext);
  }
  else
  {
    p_setNamea = &setNamea;
    setNamea.mUID = *setName;
    result = UFG::SubtitleContainer::Create(&setNamea);
    v4 = (UFG::SubtitleContainer *)result;
    if ( result )
    {
      UFG::qBaseTreeRB::Add(&UFG::SubtitleContainer::sm_Map.mTree, (UFG::qBaseNodeRB *)&result[1]);
      return (UFG::allocator::free_link *)v4;
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

