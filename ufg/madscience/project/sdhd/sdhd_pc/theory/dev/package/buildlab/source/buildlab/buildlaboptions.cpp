// File Line: 71
// RVA: 0x14F040
void __fastcall UFG::CsvDocument::~CsvDocument(UFG::CsvDocument *this)
{
  UFG::CsvDocument *v1; // rbp
  UFG::qBaseTreeRB *v2; // rdi
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseNodeRB *v4; // rsi
  Render::SkinningCacheNode *v5; // rbx

  v1 = this;
  v2 = &this->mValues.mTree.mTree;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mValues);
        i;
        i = UFG::qBaseTreeRB::GetNext(v2, &i->mRoot) )
  {
    v4 = i->mNULL.mParent;
    if ( v4 )
    {
      UFG::qString::~qString((UFG::qString *)i->mNULL.mParent);
      operator delete[](v4);
    }
    i->mNULL.mParent = 0i64;
  }
  while ( v2->mCount )
  {
    v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v2);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v2, &v5->mNode);
    operator delete[](v5);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v2);
  UFG::qString::~qString(&v1->mFilename);
}

// File Line: 92
// RVA: 0x14FE00
UFG::qString *__fastcall UFG::CsvDocument::Load(UFG::CsvDocument *this, UFG::qString *result, const char *filename, const char *key)
{
  const char *v4; // rdi
  const char *v5; // rbx
  UFG::qString *v6; // rsi
  UFG::CsvDocument *v7; // r13
  unsigned int v8; // er14
  Render::SkinningCacheNode *v9; // rbx
  char *v10; // rbx
  __int64 v11; // rcx
  __int64 v12; // r8
  UFG::qString *v13; // rax
  unsigned int v14; // er12
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString *v16; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  int v19; // esi
  UFG::qBaseNodeRB *v20; // rbx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qString *l; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v40; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+0h] [rbp-71h]
  UFG::qList<UFG::qString,UFG::qString,1,0> v46; // [rsp+10h] [rbp-61h]
  int v47; // [rsp+20h] [rbp-51h]
  UFG::qString v48; // [rsp+28h] [rbp-49h]
  UFG::qBaseNodeRB *v49; // [rsp+50h] [rbp-21h]
  __int64 v50; // [rsp+58h] [rbp-19h]
  UFG::qString resulta; // [rsp+60h] [rbp-11h]
  __int64 loaded_size; // [rsp+D0h] [rbp+5Fh]
  UFG::qString *v53; // [rsp+D8h] [rbp+67h]
  const char *v54; // [rsp+E0h] [rbp+6Fh]
  void *ptr; // [rsp+F0h] [rbp+7Fh]

  v50 = -2i64;
  v4 = key;
  v5 = filename;
  v6 = result;
  v7 = this;
  v8 = 0;
  UFG::qString::Set(&this->mFilename, 0i64);
  *(_QWORD *)&v7->mNumRows = 0i64;
  if ( v7->mValues.mTree.mTree.mCount )
  {
    do
    {
      v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v7->mValues);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v7->mValues,
        &v9->mNode);
      operator delete[](v9);
    }
    while ( v7->mValues.mTree.mTree.mCount );
    v5 = v54;
  }
  if ( UFG::qFileExists(v5) )
  {
    UFG::qString::qString(&v48);
    if ( v4 )
    {
      loaded_size = 0i64;
      v10 = UFG::qReadEntireFile(v5, &loaded_size, 0i64, 0i64, 0i64);
      if ( v10 )
      {
        v11 = 0i64;
        if ( loaded_size > 0 )
        {
          v12 = (unsigned int)ptr;
          do
          {
            v10[v11] ^= v4[v11 % v12];
            ++v11;
          }
          while ( v11 < loaded_size );
        }
        UFG::qString::Set(&v48, v10);
        UFG::qFreeEntireFile(v10, 0i64);
      }
      v5 = v54;
    }
    else
    {
      v13 = UFG::qReadString(&resulta, v5);
      UFG::qString::Set(&v48, v13->mData, v13->mLength, 0i64, 0);
      UFG::qString::~qString(&resulta);
    }
    if ( v48.mLength )
    {
      list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
      v14 = 0;
      UFG::qString::Tokenize(&v48, &list, "\n", "CsvDocument");
      v15 = list.mNode.mNext;
      loaded_size = (__int64)list.mNode.mNext;
      if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext == &list )
      {
LABEL_47:
        UFG::qString::qString(v6);
        v47 = 1;
        for ( i = (UFG::qString *)list.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
              i = (UFG::qString *)list.mNode.mNext )
        {
          v40 = i->mPrev;
          v41 = i->mNext;
          v40->mNext = v41;
          v41->mPrev = v40;
          i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
          i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
          UFG::qString::~qString(i);
          operator delete[](i);
        }
      }
      else
      {
        while ( 1 )
        {
          if ( v14 >= 0x10000 )
          {
            v6 = v53;
            UFG::qString::FormatEx(v53, "ERROR: CSV has more than 65536 rows!  filename=%s", v54);
            v47 = 1;
            for ( j = (UFG::qString *)list.mNode.mNext;
                  (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
                  j = (UFG::qString *)list.mNode.mNext )
            {
              v37 = j->mPrev;
              v38 = j->mNext;
              v37->mNext = v38;
              v38->mPrev = v37;
              j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
              j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
              UFG::qString::~qString(j);
              operator delete[](j);
            }
            goto LABEL_49;
          }
          v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          LOBYTE(v48.mNext) = 1;
          v48.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"CsvDocument";
          UFG::qTokenize(&v46, ",", (const char *)v15[1].mNext, HIDWORD(v15[1].mPrev), "CsvDocument", 1);
          v16 = (UFG::qString *)v46.mNode.mNext;
          if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46 )
            break;
LABEL_32:
          v22 = ++v14;
          if ( v7->mNumRows > v14 )
            v22 = v7->mNumRows;
          v7->mNumRows = v22;
          for ( k = (UFG::qString *)v46.mNode.mNext;
                (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46;
                k = (UFG::qString *)v46.mNode.mNext )
          {
            v24 = k->mPrev;
            v25 = k->mNext;
            v24->mNext = v25;
            v25->mPrev = v24;
            k->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
            k->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
            UFG::qString::~qString(k);
            operator delete[](k);
          }
          v26 = v46.mNode.mPrev;
          v27 = v46.mNode.mNext;
          v46.mNode.mPrev->mNext = v46.mNode.mNext;
          v27->mPrev = v26;
          v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          v15 = *(UFG::qNode<UFG::qString,UFG::qString> **)(loaded_size + 8);
          loaded_size = (__int64)v15;
          if ( v15 == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
          {
            v6 = v53;
            goto LABEL_47;
          }
          v8 = 0;
        }
        while ( 1 )
        {
          v17 = v16->mPrev;
          v18 = v16->mNext;
          v17->mNext = v18;
          v18->mPrev = v17;
          v16->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v16->mPrev;
          v16->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v16->mPrev;
          if ( v8 >= 0x10000 )
            break;
          if ( v16->mLength )
          {
            v19 = v14 | (v8 << 16);
            if ( !(v14 | (v8 << 16))
              || (v20 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v7->mValues.mTree.mTree, v19)) == 0i64 )
            {
              v20 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
              v49 = v20;
              if ( v20 )
              {
                v20->mParent = 0i64;
                v20->mChild[0] = 0i64;
                v20->mChild[1] = 0i64;
                v20->mUID = v19;
                v20[1].mParent = (UFG::qBaseNodeRB *)v16;
              }
              else
              {
                v20 = 0i64;
              }
              UFG::qBaseTreeRB::Add(&v7->mValues.mTree.mTree, v20);
            }
            v20[1].mParent = (UFG::qBaseNodeRB *)v16;
          }
          else
          {
            UFG::qString::~qString(v16);
            operator delete[](v16);
          }
          v21 = ++v8;
          if ( v7->mNumCols > v8 )
            v21 = v7->mNumCols;
          v7->mNumCols = v21;
          v16 = (UFG::qString *)v46.mNode.mNext;
          if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext == &v46 )
            goto LABEL_32;
        }
        v6 = v53;
        UFG::qString::FormatEx(v53, "ERROR: CSV has more than 65536 columns!  filename=%s", v54);
        v47 = 1;
        for ( l = (UFG::qString *)v46.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46;
              l = (UFG::qString *)v46.mNode.mNext )
        {
          v29 = l->mPrev;
          v30 = l->mNext;
          v29->mNext = v30;
          v30->mPrev = v29;
          l->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
          l->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
          UFG::qString::~qString(l);
          operator delete[](l);
        }
        v31 = v46.mNode.mPrev;
        v32 = v46.mNode.mNext;
        v46.mNode.mPrev->mNext = v46.mNode.mNext;
        v32->mPrev = v31;
        v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
        v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
        for ( m = (UFG::qString *)list.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
              m = (UFG::qString *)list.mNode.mNext )
        {
          v34 = m->mPrev;
          v35 = m->mNext;
          v34->mNext = v35;
          v35->mPrev = v34;
          m->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
          m->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
          UFG::qString::~qString(m);
          operator delete[](m);
        }
      }
LABEL_49:
      v42 = list.mNode.mPrev;
      v43 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v43->mPrev = v42;
      list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    }
    else
    {
      UFG::qString::FormatEx(v6, "ERROR: File couldnt be loaded!  filename=%s", v5);
      v47 = 1;
    }
    UFG::qString::~qString(&v48);
  }
  else
  {
    UFG::qString::FormatEx(v6, "ERROR: File not found!  filename=%s", v5);
    v47 = 1;
  }
  return v6;
}

// File Line: 200
// RVA: 0x14E9A0
void __fastcall UFG::BuildLabOption::BuildLabOption(UFG::BuildLabOption *this, const char *name, const char *value, bool is_hidden)
{
  bool v4; // r15
  const char *v5; // rbp
  const char *v6; // rsi
  UFG::BuildLabOption *v7; // r14
  unsigned int v8; // eax
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *v9; // rax

  v4 = is_hidden;
  v5 = value;
  v6 = name;
  v7 = this;
  v8 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v7->mNode.mParent = 0i64;
  v7->mNode.mChild[0] = 0i64;
  v7->mNode.mChild[1] = 0i64;
  v7->mNode.mUID = v8;
  v9 = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)&v7->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  UFG::qString::qString(&v7->mName);
  UFG::qString::qString(&v7->mValue);
  UFG::qString::Set(&v7->mName, v6);
  UFG::qString::Set(&v7->mValue, v5);
  v7->mIsHidden = v4;
}

// File Line: 221
// RVA: 0x14EA50
void __fastcall UFG::BuildLabOptionGroup::BuildLabOptionGroup(UFG::BuildLabOptionGroup *this, const char *name)
{
  const char *v2; // rdi
  UFG::BuildLabOptionGroup *v3; // rsi
  unsigned int v4; // eax
  UFG::qList<UFG::BuildLabOption,UFG::BuildLabOption,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = name;
  v3 = this;
  v4 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  UFG::qString::qString(&v3->mName);
  UFG::qBaseTreeRB::qBaseTreeRB(&v3->mOptionTree.mTree);
  v5 = &v3->mOptionList;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  UFG::qString::Set(&v3->mName, v2);
}

// File Line: 231
// RVA: 0x150E40
void __fastcall UFG::BuildLabOptionGroup::SetOption(UFG::BuildLabOptionGroup *this, const char *name, const char *value, bool is_hidden)
{
  bool v4; // r12
  const char *v5; // r13
  const char *v6; // r14
  UFG::BuildLabOptionGroup *v7; // r15
  int v8; // edx
  int v9; // ebp
  int v10; // esi
  char *v11; // rbx
  char *v12; // rdi
  unsigned int v13; // eax
  UFG::qBaseTreeRB *v14; // rbp
  UFG::qBaseTreeRB *v15; // rbx
  char *v16; // rax
  UFG::qBaseTreeRB *v17; // rax
  UFG::qBaseNodeRB *v18; // rcx
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *v19; // rax
  unsigned int v20; // eax
  char *v21; // rsi
  int v22; // eax
  _QWORD *v23; // rax
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> **v24; // rcx
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *v25; // rax
  UFG::qString result; // [rsp+20h] [rbp-458h]
  __int64 v27; // [rsp+48h] [rbp-430h]
  char text; // [rsp+50h] [rbp-428h]
  char v29; // [rsp+51h] [rbp-427h]

  v27 = -2i64;
  v4 = is_hidden;
  v5 = value;
  v6 = name;
  v7 = this;
  UFG::qTrim(&result, name, -1);
  v9 = 0;
  text = 0;
  v10 = 0;
  if ( *v6 )
  {
    v11 = (char *)v6;
    v12 = &v29;
    while ( *v11 != 46 )
    {
      if ( !UFG::qIsWhitespace(*v11) )
      {
        *(_WORD *)(v12 - 1) = (unsigned __int8)*v11;
        ++v9;
        ++v12;
      }
      ++v10;
      if ( !*++v11 )
        goto LABEL_9;
    }
    UFG::qStringCopy(&text + v9, 0x7FFFFFFF, &v6[v10], -1);
    UFG::qStringLength(&text);
  }
LABEL_9:
  v13 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    v13 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v8);
    result.mStringHashUpper32 = v13;
  }
  if ( !v13 || (v14 = &v7->mOptionTree.mTree, (v15 = UFG::qBaseTreeRB::Get(&v7->mOptionTree.mTree, v13)) == 0i64) )
  {
    v16 = UFG::qMalloc(0x88ui64, "BuildLabOption", 0i64);
    if ( v16 )
    {
      UFG::BuildLabOption::BuildLabOption((UFG::BuildLabOption *)v16, result.mData, v5, v4);
      v15 = v17;
    }
    else
    {
      v15 = 0i64;
    }
    v14 = &v7->mOptionTree.mTree;
    UFG::qBaseTreeRB::Add(&v7->mOptionTree.mTree, &v15->mRoot);
    v18 = &v15->mNULL;
    v19 = v7->mOptionList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)&v15->mNULL;
    v18->mParent = (UFG::qBaseNodeRB *)v19;
    v18->mChild[0] = (UFG::qBaseNodeRB *)&v7->mOptionList;
    v7->mOptionList.mNode.mPrev = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)&v15->mNULL;
  }
  UFG::qString::Set((UFG::qString *)&v15[1].mRoot.mChild[1], v5);
  LOBYTE(v15[1].mNULL.mUID) = v4;
  if ( UFG::qStringCompareInsensitive(&text, result.mData, -1) )
  {
    v20 = UFG::qStringHashUpper32(&text, 0xFFFFFFFF);
    if ( !v20 || (v21 = (char *)UFG::qBaseTreeRB::Get(v14, v20)) == 0i64 )
    {
      v21 = UFG::qMalloc(0x88ui64, "BuildLabOption", 0i64);
      if ( v21 )
      {
        v22 = UFG::qStringHashUpper32(&text, 0xFFFFFFFF);
        *(_QWORD *)v21 = 0i64;
        *((_QWORD *)v21 + 1) = 0i64;
        *((_QWORD *)v21 + 2) = 0i64;
        *((_DWORD *)v21 + 6) = v22;
        v23 = v21 + 32;
        *v23 = v23;
        v23[1] = v23;
        UFG::qString::qString((UFG::qString *)(v21 + 48));
        UFG::qString::qString((UFG::qString *)(v21 + 88));
        UFG::qString::Set((UFG::qString *)(v21 + 48), &text);
        UFG::qString::Set((UFG::qString *)(v21 + 88), v5);
        v21[128] = v4;
      }
      else
      {
        v21 = 0i64;
      }
      UFG::qBaseTreeRB::Add(v14, (UFG::qBaseNodeRB *)v21);
      v24 = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> **)(v21 + 32);
      v25 = v7->mOptionList.mNode.mPrev;
      v25->mNext = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)(v21 + 32);
      *v24 = v25;
      v24[1] = &v7->mOptionList.mNode;
      v7->mOptionList.mNode.mPrev = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)(v21 + 32);
    }
    UFG::qString::Set((UFG::qString *)(v21 + 88), v5);
    v21[128] = v4;
  }
  UFG::qString::~qString(&result);
}    }
    UFG::qString::Set((UFG::qString *)(v21 + 88), v5);
    v21[128] = v

// File Line: 343
// RVA: 0x14EE80
void __fastcall UFG::BuildLabDefaults::~BuildLabDefaults(UFG::BuildLabDefaults *this)
{
  UFG::BuildLabDefaults *v1; // rbx
  UFG::BuildLabOptionGroup *v2; // rdi

  v1 = this;
  v2 = this->mProjectDefault;
  if ( v2 )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mProjectDefault);
    operator delete[](v2);
  }
  v1->mProjectDefault = 0i64;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&v1->mUserRoles);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v1);
}

// File Line: 358
// RVA: 0x14F300
UFG::qBaseTreeRB *__fastcall UFG::BuildLabDefaults::Get(UFG::BuildLabDefaults *this, const char *user_role_name, const char *option_name)
{
  const char *v3; // rbx
  UFG::BuildLabDefaults *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *result; // rax

  v3 = user_role_name;
  v4 = this;
  v5 = UFG::qStringHashUpper32(option_name, 0xFFFFFFFF);
  v6 = UFG::qStringHashUpper32(v3, 0xFFFFFFFF);
  if ( !v6
    || (v7 = UFG::qBaseTreeRB::Get(&v4->mUserRoles.mTree, v6)) == 0i64
    || !v5
    || (result = UFG::qBaseTreeRB::Get(v7 + 1, v5)) == 0i64 )
  {
    if ( v5 )
      result = UFG::qBaseTreeRB::Get(&v4->mProjectDefault->mOptionTree.mTree, v5);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 400
// RVA: 0x150350
void __fastcall UFG::BuildLabDefaults::LoadProject(UFG::BuildLabDefaults *this, const char *filename, const char *key, unsigned int keyLength)
{
  unsigned int v4; // er14
  const char *v5; // rbx
  const char *v6; // rdi
  UFG::BuildLabDefaults *v7; // rsi
  UFG::BuildLabOptionGroup *v8; // r13
  char *v9; // rsi
  __int64 v10; // rcx
  int i; // edx
  SimpleXML::XMLDocument *v12; // rax
  SimpleXML::XMLDocument *v13; // r15
  SimpleXML::XMLNode *v14; // rax
  SimpleXML::XMLNode *v15; // rdi
  char *v16; // rax
  SimpleXML::XMLNode *v17; // rbx
  char *v18; // rax
  SimpleXML::XMLNode *v19; // rax
  SimpleXML::XMLNode *v20; // r15
  char *v21; // rax
  char *v22; // rbx
  char *v23; // rsi
  char *v24; // r12
  char *v25; // r14
  char *v26; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rbx
  UFG::qString *v28; // rax
  const char *v29; // r8
  UFG::qString *l; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+8h] [rbp-59h]
  UFG::qList<UFG::qString,UFG::qString,1,0> v41; // [rsp+18h] [rbp-49h]
  bool add_empty_strings[8]; // [rsp+28h] [rbp-39h]
  __int64 loaded_size; // [rsp+30h] [rbp-31h]
  SimpleXML::XMLNode *j; // [rsp+38h] [rbp-29h]
  void *ptr; // [rsp+40h] [rbp-21h]
  SimpleXML::XMLNode *k; // [rsp+48h] [rbp-19h]
  SimpleXML::XMLNode *v47; // [rsp+50h] [rbp-11h]
  SimpleXML::XMLNode *prev_node; // [rsp+58h] [rbp-9h]
  __int64 v49; // [rsp+60h] [rbp-1h]
  UFG::qString result; // [rsp+68h] [rbp+7h]

  v49 = -2i64;
  v4 = keyLength;
  v5 = key;
  v6 = filename;
  v7 = this;
  if ( UFG::qFileExists(filename) )
  {
    v8 = v7->mProjectDefault;
    ptr = 0i64;
    if ( v5 )
    {
      loaded_size = 0i64;
      v9 = UFG::qReadEntireFile(v6, &loaded_size, 0i64, 0i64, 0i64);
      ptr = v9;
      if ( !v9 )
        return;
      v10 = 0i64;
      for ( i = loaded_size; v10 < loaded_size; i = loaded_size )
      {
        v9[v10] ^= v5[v10 % v4];
        ++v10;
      }
      v12 = (SimpleXML::XMLDocument *)SimpleXML::XMLDocument::OpenBuffer(v9, i);
    }
    else
    {
      v12 = SimpleXML::XMLDocument::Open(v6, 1ui64, 0i64);
    }
    v13 = v12;
    *(_QWORD *)add_empty_strings = v12;
    if ( v12 )
    {
      v14 = SimpleXML::XMLDocument::GetNode(v12, "BuildLab", 0i64);
      if ( v14 )
      {
        v15 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v14);
        for ( j = v15; v15; j = v15 )
        {
          v16 = SimpleXML::XMLNode::GetName(v15);
          if ( !UFG::qStringCompareInsensitive(v16, "Pipeline", -1) )
          {
            v17 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v15);
            v47 = v17;
            if ( v17 )
            {
              do
              {
                v18 = SimpleXML::XMLNode::GetName(v17);
                if ( !UFG::qStringCompareInsensitive(v18, "Tabs", -1) )
                {
                  v19 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v17);
                  prev_node = v19;
                  if ( v19 )
                  {
                    do
                    {
                      v20 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v19);
                      for ( k = v20; v20; k = v20 )
                      {
                        v21 = SimpleXML::XMLNode::GetName(v20);
                        if ( !UFG::qStringCompareInsensitive(v21, "Object", -1) )
                        {
                          v22 = SimpleXML::XMLNode::GetAttribute(v20, "type");
                          v23 = SimpleXML::XMLNode::GetAttribute(v20, "name");
                          v24 = SimpleXML::XMLNode::GetAttribute(v20, "defaults");
                          v25 = SimpleXML::XMLNode::GetAttribute(v20, "value");
                          SimpleXML::XMLNode::GetAttribute(v20, "comboDefaults");
                          v26 = SimpleXML::XMLNode::GetAttribute(v20, "comboValue");
                          if ( UFG::qStringCompareInsensitive(v22, "CheckBox", -1)
                            && UFG::qStringCompareInsensitive(v22, "ComboBox", -1)
                            && UFG::qStringCompareInsensitive(v22, "String", -1) )
                          {
                            if ( !UFG::qStringCompareInsensitive(v22, "ArrayList", -1) )
                            {
                              if ( v26 && *v26 )
                                UFG::BuildLabOptionGroup::SetOption(v8, v23, v26, 0);
                              UFG::qTokenize(&list, ",", v24, 0, 0i64, 0);
                              UFG::qTokenize(&v41, ",", v25, 0, 0i64, 0);
                              v27 = list.mNode.mNext;
                              if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list )
                              {
                                do
                                {
                                  UFG::qString::FormatEx(&result, "%s.%s", v23, v27[1].mNext);
                                  v28 = UFG::qFindString(&v41, (const char *)v27[1].mNext, 1);
                                  v29 = "False";
                                  if ( v28 )
                                    v29 = "True";
                                  UFG::BuildLabOptionGroup::SetOption(v8, result.mData, v29, 0);
                                  UFG::qString::~qString(&result);
                                  v27 = v27->mNext;
                                }
                                while ( v27 != (UFG::qNode<UFG::qString,UFG::qString> *)&list );
                                v20 = k;
                              }
                              for ( l = (UFG::qString *)v41.mNode.mNext;
                                    (UFG::qList<UFG::qString,UFG::qString,1,0> *)v41.mNode.mNext != &v41;
                                    l = (UFG::qString *)v41.mNode.mNext )
                              {
                                v31 = l->mPrev;
                                v32 = l->mNext;
                                v31->mNext = v32;
                                v32->mPrev = v31;
                                l->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
                                l->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
                                UFG::qString::~qString(l);
                                operator delete[](l);
                              }
                              v33 = v41.mNode.mPrev;
                              v34 = v41.mNode.mNext;
                              v41.mNode.mPrev->mNext = v41.mNode.mNext;
                              v34->mPrev = v33;
                              v41.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v41;
                              v41.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v41;
                              for ( m = (UFG::qString *)list.mNode.mNext;
                                    (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
                                    m = (UFG::qString *)list.mNode.mNext )
                              {
                                v36 = m->mPrev;
                                v37 = m->mNext;
                                v36->mNext = v37;
                                v37->mPrev = v36;
                                m->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
                                m->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
                                UFG::qString::~qString(m);
                                operator delete[](m);
                              }
                              v38 = list.mNode.mPrev;
                              v39 = list.mNode.mNext;
                              list.mNode.mPrev->mNext = list.mNode.mNext;
                              v39->mPrev = v38;
                              list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
                              list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
                            }
                          }
                          else
                          {
                            UFG::BuildLabOptionGroup::SetOption(v8, v23, v25, 0);
                          }
                        }
                        v20 = SimpleXML::XMLDocument::GetNode(*(SimpleXML::XMLDocument **)add_empty_strings, 0i64, v20);
                      }
                      v13 = *(SimpleXML::XMLDocument **)add_empty_strings;
                      v19 = SimpleXML::XMLDocument::GetNode(
                              *(SimpleXML::XMLDocument **)add_empty_strings,
                              0i64,
                              prev_node);
                      prev_node = v19;
                    }
                    while ( v19 );
                    v17 = v47;
                  }
                }
                v17 = SimpleXML::XMLDocument::GetNode(v13, 0i64, v17);
                v47 = v17;
              }
              while ( v17 );
              v15 = j;
            }
          }
          v15 = SimpleXML::XMLDocument::GetNode(v13, 0i64, v15);
        }
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
        if ( ptr )
          UFG::qFreeEntireFile(ptr, 0i64);
      }
      else
      {
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
      }
    }
  }
}

// File Line: 547
// RVA: 0x14F920
UFG::qString *__fastcall UFG::BuildLabDefaults::Load(UFG::BuildLabDefaults *this, UFG::qString *result, const char *project_filename, const char *defaults_filename, const char *key, unsigned int keyLength)
{
  const char *v6; // rdi
  const char *v7; // rbx
  UFG::qString *v8; // r15
  UFG::BuildLabDefaults *v9; // r13
  unsigned int v10; // esi
  unsigned int v11; // er14
  unsigned __int64 v12; // kr00_8
  unsigned __int64 v13; // kr08_8
  unsigned int v14; // ebx
  unsigned int v15; // edi
  UFG::qBaseTreeRB *v16; // rax
  __int64 *v17; // rax
  const char *v18; // rdx
  int v19; // edx
  unsigned int v20; // eax
  UFG::BuildLabOptionGroup *v21; // r12
  char *v22; // rax
  UFG::BuildLabOptionGroup *v23; // rax
  unsigned int v24; // er15
  UFG::qBaseTreeRB *v25; // rax
  __int64 *v26; // rax
  const char *v27; // rdx
  UFG::qBaseTreeRB *v28; // rax
  UFG::qBaseTreeRB **v29; // rax
  const char *v30; // rdx
  bool v31; // r14
  UFG::qString *v32; // rax
  char *v33; // rdi
  UFG::BuildLabOptionGroup *v34; // rsi
  signed __int64 v35; // rbx
  signed __int64 v36; // rsi
  char *v37; // rsi
  signed __int64 v38; // rdi
  unsigned int v40; // [rsp+30h] [rbp-D0h]
  signed int v41; // [rsp+38h] [rbp-C8h]
  UFG::qBaseTreeRB *v42; // [rsp+40h] [rbp-C0h]
  unsigned int v43; // [rsp+48h] [rbp-B8h]
  __int64 v44; // [rsp+50h] [rbp-B0h]
  __int64 v45; // [rsp+58h] [rbp-A8h]
  UFG::qString v46; // [rsp+60h] [rbp-A0h]
  UFG::qString v47; // [rsp+88h] [rbp-78h]
  UFG::qString v48; // [rsp+B0h] [rbp-50h]
  UFG::qString resulta; // [rsp+D8h] [rbp-28h]
  UFG::qString v50; // [rsp+100h] [rbp+0h]
  UFG::qBaseTreeRB v51; // [rsp+128h] [rbp+28h]
  unsigned __int64 v52; // [rsp+170h] [rbp+70h]
  __int64 v53; // [rsp+180h] [rbp+80h]
  UFG::qString v54; // [rsp+188h] [rbp+88h]
  unsigned int v55; // [rsp+1F0h] [rbp+F0h]
  UFG::qString *v56; // [rsp+1F8h] [rbp+F8h]

  v56 = result;
  v53 = -2i64;
  v6 = defaults_filename;
  v7 = project_filename;
  v8 = result;
  v9 = this;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&this->mUserRoles);
  UFG::qTreeRB<UFG::BuildLabOption,UFG::BuildLabOption,0>::DeleteAll(&v9->mProjectDefault->mOptionTree);
  UFG::BuildLabDefaults::LoadProject(v9, v7, key, keyLength);
  if ( !UFG::qFileExists(v6) )
    goto LABEL_64;
  UFG::qString::qString(&v50);
  v42 = &v51;
  UFG::qBaseTreeRB::qBaseTreeRB(&v51);
  UFG::qString::Set(&v50, 0i64);
  v52 = 0i64;
  UFG::CsvDocument::Load((UFG::CsvDocument *)&v50, &resulta, v6, key);
  v12 = v52;
  v11 = v12 >> 32;
  v10 = v12;
  v13 = v52;
  v43 = v13 >> 32;
  v40 = v13;
  if ( !resulta.mLength )
  {
    if ( (unsigned int)v52 <= 1 || HIDWORD(v52) <= 1 )
    {
      UFG::qString::qString(v8);
      UFG::qString::~qString(&resulta);
      UFG::CsvDocument::~CsvDocument((UFG::CsvDocument *)&v50);
      return v8;
    }
    v14 = 1;
    v41 = 1;
    if ( HIDWORD(v52) > 1 )
    {
      v45 = 0i64;
      do
      {
        v15 = (unsigned __int16)v14 << 16;
        v55 = v15;
        if ( v15 && (v16 = UFG::qBaseTreeRB::Get(&v51, v15)) != 0i64 )
          v17 = (__int64 *)&v16->mNULL;
        else
          v17 = &v45;
        if ( *v17 )
          v18 = *(const char **)(*v17 + 24);
        else
          v18 = 0i64;
        UFG::qTrim(&v47, v18, -1);
        if ( v47.mLength )
        {
          v20 = v47.mStringHashUpper32;
          if ( v47.mStringHashUpper32 == -1 )
          {
            v20 = UFG::qStringHashUpper32(v47.mData, v47.mStringHashUpper32 | v19);
            v47.mStringHashUpper32 = v20;
          }
          if ( !v20 || (v21 = (UFG::BuildLabOptionGroup *)UFG::qBaseTreeRB::Get(&v9->mUserRoles.mTree, v20)) == 0i64 )
          {
            v22 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
            v42 = (UFG::qBaseTreeRB *)v22;
            if ( v22 )
            {
              UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v22, v47.mData);
              v21 = v23;
            }
            else
            {
              v21 = 0i64;
            }
            UFG::qBaseTreeRB::Add(&v9->mUserRoles.mTree, &v21->mNode);
          }
          v24 = 1;
          if ( v10 > 1 )
          {
            v44 = 0i64;
            v42 = 0i64;
            do
            {
              if ( (_WORD)v24 && (v25 = UFG::qBaseTreeRB::Get(&v51, (unsigned __int16)v24)) != 0i64 )
                v26 = (__int64 *)&v25->mNULL;
              else
                v26 = &v44;
              if ( *v26 )
                v27 = *(const char **)(*v26 + 24);
              else
                v27 = 0i64;
              UFG::qTrim(&v46, v27, -1);
              if ( (unsigned __int16)v24 | v15
                && (v28 = UFG::qBaseTreeRB::Get(&v51, (unsigned __int16)v24 | v15)) != 0i64 )
              {
                v29 = (UFG::qBaseTreeRB **)&v28->mNULL;
              }
              else
              {
                v29 = &v42;
              }
              if ( *v29 )
                v30 = *(const char **)&(*v29)->mRoot.mUID;
              else
                v30 = 0i64;
              UFG::qTrim(&v48, v30, -1);
              v31 = 0;
              if ( v46.mLength )
              {
                if ( (unsigned int)UFG::qString::StartsWith(&v48, "!", -1) )
                {
                  v32 = UFG::qString::Substring(&v48, &v54, 1, -1);
                  UFG::qString::Set(&v48, v32->mData, v32->mLength, 0i64, 0);
                  UFG::qString::~qString(&v54);
                  v31 = 1;
                }
                if ( UFG::qStringFind(v46.mData, pattern) || UFG::qStringFind(v46.mData, "?") )
                {
                  v33 = v46.mData;
                  v34 = v9->mProjectDefault;
                  if ( v46.mData )
                  {
                    if ( *v46.mData )
                    {
                      v35 = (signed __int64)&v34->mOptionList.mNode.mNext[-2];
                      v36 = (signed __int64)v34->mOptionTree.mTree.mNULL.mChild;
                      if ( v35 != v36 )
                      {
                        while ( !UFG::qWildcardMatchInsensitive(v33, *(const char **)(v35 + 72)) )
                        {
                          v35 = *(_QWORD *)(v35 + 40) - 32i64;
                          if ( v35 == v36 )
                            goto LABEL_57;
                        }
                        while ( 1 )
                        {
                          UFG::BuildLabOptionGroup::SetOption(v21, *(const char **)(v35 + 72), v48.mData, v31);
                          v37 = v46.mData;
                          if ( !v46.mData )
                            break;
                          if ( !*v46.mData )
                            break;
                          v35 = *(_QWORD *)(v35 + 40) - 32i64;
                          v38 = (signed __int64)v9->mProjectDefault->mOptionTree.mTree.mNULL.mChild;
                          if ( v35 == v38 )
                            break;
                          while ( !UFG::qWildcardMatchInsensitive(v37, *(const char **)(v35 + 72)) )
                          {
                            v35 = *(_QWORD *)(v35 + 40) - 32i64;
                            if ( v35 == v38 )
                              goto LABEL_57;
                          }
                        }
                      }
                    }
                  }
LABEL_57:
                  v15 = v55;
                  v10 = v40;
                }
                else
                {
                  UFG::BuildLabOptionGroup::SetOption(v21, v46.mData, v48.mData, v31);
                }
              }
              UFG::qString::~qString(&v48);
              UFG::qString::~qString(&v46);
              ++v24;
            }
            while ( v24 < v10 );
            v14 = v41;
            v11 = v43;
          }
        }
        UFG::qString::~qString(&v47);
        v41 = ++v14;
      }
      while ( v14 < v11 );
      v8 = v56;
    }
    UFG::qString::~qString(&resulta);
    UFG::CsvDocument::~CsvDocument((UFG::CsvDocument *)&v50);
LABEL_64:
    UFG::qString::qString(v8);
    return v8;
  }
  UFG::qString::qString(v8, &resulta);
  UFG::qString::~qString(&resulta);
  UFG::CsvDocument::~CsvDocument((UFG::CsvDocument *)&v50);
  return v8;
}

// File Line: 673
// RVA: 0x14EAE0
void __fastcall UFG::BuildLabOptions::BuildLabOptions(UFG::BuildLabOptions *this, const char *user_options_filename, UFG::BuildLabOptions::LoadOptions load_options, const char *key, unsigned int keyLength)
{
  const char *v5; // rsi
  char v6; // r15
  const char *v7; // r12
  UFG::BuildLabOptions *v8; // rbx
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  char *v15; // rax
  char *v16; // rax
  UFG::qString result; // [rsp+40h] [rbp-31h]
  UFG::qString v18; // [rsp+68h] [rbp-9h]

  v5 = key;
  v6 = load_options;
  v7 = user_options_filename;
  v8 = this;
  UFG::qString::qString(&this->mProjectFilename);
  UFG::qString::qString(&v8->mDefaultsFilename);
  UFG::qString::qString(&v8->mUserOptionsFilename);
  UFG::qString::qString(&v8->mUserRoleName);
  UFG::qBaseTreeRB::qBaseTreeRB(&v8->mDefaults.mUserRoles.mTree);
  v9 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v9 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v9, "ProjectDefault");
  v8->mDefaults.mProjectDefault = (UFG::BuildLabOptionGroup *)v9;
  v10 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v10 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v10, "ProjectOptions");
  v8->mProjectOptionGroup = (UFG::BuildLabOptionGroup *)v10;
  v11 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v11 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v11, "UserOptions");
  v8->mUserOptionGroup = (UFG::BuildLabOptionGroup *)v11;
  v8->mEnableDiagnostics = 0;
  UFG::qString::Set(&v8->mUserOptionsFilename, v7);
  UFG::qString::GetFilePath(&v8->mUserOptionsFilename, &result);
  if ( result.mLength
    && !(unsigned int)UFG::qString::EndsWith(&result, "\\", -1)
    && !(unsigned int)UFG::qString::EndsWith(&result, "/", -1) )
  {
    UFG::qString::operator+=(&result, "\\");
  }
  if ( v5 )
  {
    v12 = UFG::qString::FormatEx(&v18, "%sBuildLab.project.dat", result.mData);
    UFG::qString::Set(&v8->mProjectFilename, v12->mData, v12->mLength, 0i64, 0);
    UFG::qString::~qString(&v18);
    v13 = UFG::qString::FormatEx(&v18, "%sBuildLab.defaults.dat", result.mData);
  }
  else
  {
    v14 = UFG::qString::FormatEx(&v18, "%sBuildLab.project.xml", result.mData);
    UFG::qString::Set(&v8->mProjectFilename, v14->mData, v14->mLength, 0i64, 0);
    UFG::qString::~qString(&v18);
    v13 = UFG::qString::FormatEx(&v18, "%sBuildLab.defaults.csv", result.mData);
  }
  UFG::qString::Set(&v8->mDefaultsFilename, v13->mData, v13->mLength, 0i64, 0);
  UFG::qString::~qString(&v18);
  if ( v6 & 2 )
    UFG::BuildLabOptions::LoadProjectFile(v8, v8->mProjectFilename.mData, v5, keyLength);
  if ( v6 & 1 )
  {
    UFG::BuildLabOptions::LoadUserFile(v8, v8->mUserOptionsFilename.mData, v5, keyLength);
    UFG::BuildLabDefaults::Load(
      &v8->mDefaults,
      &v18,
      v8->mProjectFilename.mData,
      v8->mDefaultsFilename.mData,
      v5,
      keyLength);
    UFG::qString::~qString(&v18);
  }
  v15 = UFG::BuildLabOptions::GetValue(v8, "UserRole", 0i64);
  UFG::qString::Set(&v8->mUserRoleName, v15);
  v16 = UFG::BuildLabOptions::GetValue(v8, "Diagnostics", &customWorldMapCaption);
  v8->mEnableDiagnostics = UFG::qToBool(v16, 0);
  UFG::qString::~qString(&result);
}

// File Line: 729
// RVA: 0x14EF50
void __fastcall UFG::BuildLabOptions::~BuildLabOptions(UFG::BuildLabOptions *this)
{
  UFG::BuildLabOptions *v1; // rbx
  UFG::BuildLabOptionGroup *v2; // rdi
  UFG::BuildLabOptionGroup *v3; // rdi
  UFG::BuildLabOptionGroup *v4; // rsi

  v1 = this;
  v2 = this->mProjectOptionGroup;
  if ( v2 )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mProjectOptionGroup);
    operator delete[](v2);
  }
  v3 = v1->mUserOptionGroup;
  if ( v3 )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(v1->mUserOptionGroup);
    operator delete[](v3);
  }
  v1->mProjectOptionGroup = 0i64;
  v1->mUserOptionGroup = 0i64;
  v4 = v1->mDefaults.mProjectDefault;
  if ( v4 )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(v1->mDefaults.mProjectDefault);
    operator delete[](v4);
  }
  v1->mDefaults.mProjectDefault = 0i64;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&v1->mDefaults.mUserRoles);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mDefaults);
  UFG::qString::~qString(&v1->mUserRoleName);
  UFG::qString::~qString(&v1->mUserOptionsFilename);
  UFG::qString::~qString(&v1->mDefaultsFilename);
  UFG::qString::~qString(&v1->mProjectFilename);
}

// File Line: 913
// RVA: 0x14F8E0
char *__fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name)
{
  return UFG::BuildLabOptions::GetValue(this, option_name, 0i64);
}

// File Line: 918
// RVA: 0x14F7D0
char *__fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name, const char *default_value)
{
  const char *v3; // r14
  const char *v4; // rsi
  UFG::BuildLabOptions *v5; // rbp
  UFG::qBaseTreeRB *v6; // rax
  char v7; // r15
  UFG::qBaseTreeRB *v8; // rax
  const char *v9; // rdi
  UFG::BuildLabOptionGroup *v10; // rbp
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *v11; // rbx
  signed __int64 v12; // rbp
  signed __int64 v13; // rbx

  v3 = default_value;
  v4 = option_name;
  v5 = this;
  v6 = UFG::BuildLabDefaults::Get(&this->mDefaults, this->mUserRoleName.mData, option_name);
  if ( v6 )
    v7 = v6[1].mNULL.mUID;
  else
    v7 = 0;
  v8 = UFG::BuildLabDefaults::Get(&v5->mDefaults, v5->mUserRoleName.mData, v4);
  if ( v8 )
    v9 = (const char *)v8[1].mNULL.mChild[0];
  else
    v9 = 0i64;
  v10 = v5->mUserOptionGroup;
  if ( v4
    && *v4
    && (v11 = v10->mOptionList.mNode.mNext,
        v12 = (signed __int64)v10->mOptionTree.mTree.mNULL.mChild,
        v13 = (signed __int64)&v11[-2],
        v13 != v12) )
  {
    while ( !UFG::qWildcardMatchInsensitive(v4, *(const char **)(v13 + 72)) )
    {
      v13 = *(_QWORD *)(v13 + 40) - 32i64;
      if ( v13 == v12 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v13 = 0i64;
  }
  if ( v7 )
    return (char *)v9;
  if ( v13 )
    return *(char **)(v13 + 112);
  if ( v9 )
    v3 = v9;
  return (char *)v3;
}

// File Line: 946
// RVA: 0x14F7A0
int __fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name, int default_value)
{
  int v3; // ebx
  char *v4; // rax

  v3 = default_value;
  v4 = UFG::BuildLabOptions::GetValue(this, option_name, &customWorldMapCaption);
  return UFG::qToInt32(v4, v3);
}

// File Line: 950
// RVA: 0x14F8F0
char __fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name, bool default_value)
{
  bool v3; // bl
  char *v4; // rax

  v3 = default_value;
  v4 = UFG::BuildLabOptions::GetValue(this, option_name, &customWorldMapCaption);
  return UFG::qToBool(v4, v3);
}

// File Line: 953
// RVA: 0x14F390
void __fastcall UFG::BuildLabOptions::GetNames(UFG::BuildLabOptions *this, UFG::qList<UFG::qString,UFG::qString,1,0> *option_list, const char *option_name_pattern, const char *option_value_pattern, const char *strip_prefix)
{
  const char *v5; // rsi
  const char *v6; // r14
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // r15
  UFG::BuildLabOptions *v8; // r13
  __int64 v9; // r12
  UFG::BuildLabOptionGroup *v10; // rdi
  signed __int64 v11; // rbx
  signed __int64 v12; // rdi
  char *v13; // rax
  char *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  char *v18; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  signed __int64 v22; // rdi
  UFG::BuildLabOptionGroup *v23; // rdi
  signed __int64 v24; // rbx
  signed __int64 v25; // rdi
  const char *v26; // rsi
  UFG::BuildLabOptionGroup *v27; // rbp
  signed __int64 v28; // rdi
  signed __int64 v29; // rbp
  char *v30; // rax
  char *v31; // rax
  UFG::qString *v32; // rax
  UFG::qString *v33; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  char *v35; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  signed __int64 v39; // rdi
  char *pattern; // [rsp+88h] [rbp+20h]

  pattern = (char *)option_value_pattern;
  v5 = option_value_pattern;
  v6 = option_name_pattern;
  v7 = option_list;
  v8 = this;
  if ( this->mEnableDiagnostics )
    UFG::qPrintf("[BuildLabOptions::GetNames] %-20s -> ", option_name_pattern);
  v9 = (signed int)UFG::qStringLength(strip_prefix);
  v10 = v8->mDefaults.mProjectDefault;
  if ( v6 )
  {
    if ( *v6 )
    {
      v11 = (signed __int64)&v10->mOptionList.mNode.mNext[-2];
      v12 = (signed __int64)v10->mOptionTree.mTree.mNULL.mChild;
      if ( v11 != v12 )
      {
        while ( !UFG::qWildcardMatchInsensitive(v6, *(const char **)(v11 + 72)) )
        {
          v11 = *(_QWORD *)(v11 + 40) - 32i64;
          if ( v11 == v12 )
            goto LABEL_28;
        }
        while ( 1 )
        {
          v13 = UFG::BuildLabOptions::GetValue(v8, *(const char **)(v11 + 72), 0i64);
          if ( UFG::qWildcardMatchInsensitive(v5, v13) )
          {
            if ( (signed int)v9 <= 0 )
            {
              if ( v8->mEnableDiagnostics )
                UFG::qPrintf("%s  ", *(_QWORD *)(v11 + 72));
              v18 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
              if ( v18 )
              {
                UFG::qString::qString((UFG::qString *)v18, (UFG::qString *)(v11 + 48));
                v20 = v19;
              }
              else
              {
                v20 = 0i64;
              }
              v21 = v7->mNode.mPrev;
              v21->mNext = v20;
              v20->mPrev = v21;
              v20->mNext = &v7->mNode;
              v7->mNode.mPrev = v20;
            }
            else if ( *(_DWORD *)(v11 + 68) - (signed int)v9 > 0 )
            {
              v14 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
              if ( v14 )
              {
                UFG::qString::qString((UFG::qString *)v14);
                v16 = v15;
              }
              else
              {
                v16 = 0i64;
              }
              UFG::qString::Set(v16, (const char *)(*(_QWORD *)(v11 + 72) + v9));
              if ( v8->mEnableDiagnostics )
                UFG::qPrintf("%s  ", v16->mData);
              v17 = v7->mNode.mPrev;
              v17->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v16->mPrev;
              v16->mPrev = v17;
              v16->mNext = &v7->mNode;
              v7->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v16->mPrev;
            }
          }
          if ( !*v6 )
            break;
          v11 = *(_QWORD *)(v11 + 40) - 32i64;
          v22 = (signed __int64)v8->mDefaults.mProjectDefault->mOptionTree.mTree.mNULL.mChild;
          if ( v11 == v22 )
            break;
          while ( !UFG::qWildcardMatchInsensitive(v6, *(const char **)(v11 + 72)) )
          {
            v11 = *(_QWORD *)(v11 + 40) - 32i64;
            if ( v11 == v22 )
              goto LABEL_28;
          }
        }
      }
    }
  }
LABEL_28:
  v23 = v8->mUserOptionGroup;
  if ( v6 )
  {
    if ( *v6 )
    {
      v24 = (signed __int64)&v23->mOptionList.mNode.mNext[-2];
      v25 = (signed __int64)v23->mOptionTree.mTree.mNULL.mChild;
      if ( v24 != v25 )
      {
        while ( !UFG::qWildcardMatchInsensitive(v6, *(const char **)(v24 + 72)) )
        {
          v24 = *(_QWORD *)(v24 + 40) - 32i64;
          if ( v24 == v25 )
            return;
        }
        while ( 1 )
        {
          v26 = *(const char **)(v24 + 72);
          v27 = v8->mDefaults.mProjectDefault;
          if ( v26
            && *v26
            && (v28 = (signed __int64)&v27->mOptionList.mNode.mNext[-2],
                v29 = (signed __int64)v27->mOptionTree.mTree.mNULL.mChild,
                v28 != v29) )
          {
            while ( !UFG::qWildcardMatchInsensitive(v26, *(const char **)(v28 + 72)) )
            {
              v28 = *(_QWORD *)(v28 + 40) - 32i64;
              if ( v28 == v29 )
                goto LABEL_39;
            }
          }
          else
          {
LABEL_39:
            v30 = UFG::BuildLabOptions::GetValue(v8, *(const char **)(v24 + 72), 0i64);
            if ( UFG::qWildcardMatchInsensitive(pattern, v30) )
            {
              if ( (signed int)v9 <= 0 )
              {
                if ( v8->mEnableDiagnostics )
                  UFG::qPrintf("%s  ", *(_QWORD *)(v24 + 72));
                v35 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
                if ( v35 )
                {
                  UFG::qString::qString((UFG::qString *)v35, (UFG::qString *)(v24 + 48));
                  v37 = v36;
                }
                else
                {
                  v37 = 0i64;
                }
                v38 = v7->mNode.mPrev;
                v38->mNext = v37;
                v37->mPrev = v38;
                v37->mNext = &v7->mNode;
                v7->mNode.mPrev = v37;
              }
              else if ( *(_DWORD *)(v24 + 68) - (signed int)v9 > 0 )
              {
                v31 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
                if ( v31 )
                {
                  UFG::qString::qString((UFG::qString *)v31);
                  v33 = v32;
                }
                else
                {
                  v33 = 0i64;
                }
                UFG::qString::Set(v33, (const char *)(*(_QWORD *)(v24 + 72) + v9));
                if ( v8->mEnableDiagnostics )
                  UFG::qPrintf("%s  ", v33->mData);
                v34 = v7->mNode.mPrev;
                v34->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v33->mPrev;
                v33->mPrev = v34;
                v33->mNext = &v7->mNode;
                v7->mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v33->mPrev;
              }
            }
          }
          if ( !*v6 )
            break;
          v24 = *(_QWORD *)(v24 + 40) - 32i64;
          v39 = (signed __int64)v8->mUserOptionGroup->mOptionTree.mTree.mNULL.mChild;
          if ( v24 == v39 )
            break;
          while ( !UFG::qWildcardMatchInsensitive(v6, *(const char **)(v24 + 72)) )
          {
            v24 = *(_QWORD *)(v24 + 40) - 32i64;
            if ( v24 == v39 )
              return;
          }
        }
      }
    }
  }
}

// File Line: 1067
// RVA: 0x1508A0
void __fastcall UFG::BuildLabOptions::LoadProjectFile(UFG::BuildLabOptions *this, const char *filename, const char *obfuscateKey, unsigned int obfuscateKeyLength)
{
  __int64 v4; // rsi
  const char *v5; // rdi
  UFG::BuildLabOptions *v6; // r14
  char v7; // bp
  UFG::qString *v8; // rax
  __int64 v9; // rbx
  char *v10; // r8
  int v11; // ecx
  UFG::qMemoryPool **v12; // rax
  SimpleXML::XMLDocument *v13; // rsi
  SimpleXML::XMLNode *v14; // rax
  SimpleXML::XMLNode *i; // rdi
  char *v16; // rax
  char *v17; // rbx
  const char *v18; // rax
  UFG::qString v19; // [rsp+38h] [rbp-70h]
  UFG::qString result; // [rsp+60h] [rbp-48h]
  __int64 loaded_size; // [rsp+C0h] [rbp+18h]

  v4 = obfuscateKeyLength;
  v5 = obfuscateKey;
  v6 = this;
  v7 = 0;
  UFG::qString::qString(&v19, filename);
  if ( v5 && (_DWORD)v4 )
  {
    v8 = UFG::qString::ReplaceExtension(&v19, &result, ".dat");
    UFG::qString::Set(&v19, v8->mData);
    UFG::qString::~qString(&result);
    v7 = 1;
  }
  if ( UFG::qFileExists(v19.mData) )
  {
    v9 = 0i64;
    loaded_size = 0i64;
    v10 = UFG::qReadEntireFile(v19.mData, &loaded_size, 0i64, 0i64, 0i64);
    v11 = loaded_size;
    if ( (v10 != 0i64) & (unsigned __int8)v7 && loaded_size > 0 )
    {
      do
      {
        v10[v9] ^= v5[v9 % v4];
        ++v9;
        v11 = loaded_size;
      }
      while ( v9 < loaded_size );
    }
    v12 = SimpleXML::XMLDocument::OpenBuffer(v10, v11);
    v13 = (SimpleXML::XMLDocument *)v12;
    if ( v12 )
    {
      v14 = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v12, "BuildLab", 0i64);
      if ( v14 )
      {
        for ( i = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v14); i; i = SimpleXML::XMLDocument::GetNode(
                                                                                 v13,
                                                                                 0i64,
                                                                                 i) )
        {
          v16 = SimpleXML::XMLNode::GetName(i);
          if ( !UFG::qStringCompareInsensitive(v16, "Param", -1) )
          {
            v17 = SimpleXML::XMLNode::GetAttribute(i, "key");
            v18 = SimpleXML::XMLNode::GetValue(i);
            UFG::BuildLabOptionGroup::SetOption(v6->mProjectOptionGroup, v17, v18, 0);
          }
        }
      }
      SimpleXML::XMLDocument::~XMLDocument(v13);
      operator delete[](v13);
    }
  }
  UFG::qString::~qString(&v19);
}

// File Line: 1126
// RVA: 0x150A70
void __fastcall UFG::BuildLabOptions::LoadUserFile(UFG::BuildLabOptions *this, const char *filename, const char *obfuscateKey, unsigned int obfuscateKeyLength)
{
  __int64 v4; // rdi
  const char *v5; // rbx
  UFG::BuildLabOptions *v6; // r15
  char v7; // si
  UFG::qString *v8; // rax
  char *v9; // r13
  int v10; // edx
  __int64 i; // rcx
  UFG::qMemoryPool **v12; // rax
  SimpleXML::XMLDocument *v13; // r14
  SimpleXML::XMLNode *v14; // rax
  UFG::BuildLabOptionGroup *v15; // r15
  SimpleXML::XMLNode *j; // r12
  char *v17; // rax
  char *v18; // rax
  char *v19; // rax
  char *v20; // rbx
  const char *v21; // rax
  const char *v22; // rbx
  char *v23; // rax
  SimpleXML::XMLNode *k; // rsi
  char *v25; // rax
  char *v26; // rbx
  char *v27; // rax
  UFG::qString *v28; // rax
  char *v29; // rax
  SimpleXML::XMLNode *v30; // rbx
  const char *v31; // rax
  const char *v32; // rdi
  UFG::qString *v33; // rax
  const char *v34; // rax
  UFG::qString lhs; // [rsp+30h] [rbp-71h]
  UFG::qString result; // [rsp+58h] [rbp-49h]
  __int64 v37; // [rsp+80h] [rbp-21h]
  UFG::qString v38; // [rsp+88h] [rbp-19h]
  UFG::qString v39; // [rsp+B0h] [rbp+Fh]
  __int64 loaded_size; // [rsp+118h] [rbp+77h]

  v37 = -2i64;
  v4 = obfuscateKeyLength;
  v5 = obfuscateKey;
  v6 = this;
  v7 = 0;
  UFG::qString::qString(&lhs, filename);
  if ( v5 && (_DWORD)v4 )
  {
    v8 = UFG::qString::ReplaceExtension(&lhs, &result, ".dat");
    UFG::qString::Set(&lhs, v8->mData);
    UFG::qString::~qString(&result);
    v7 = 1;
  }
  if ( UFG::qFileExists(lhs.mData) )
  {
    loaded_size = 0i64;
    v9 = UFG::qReadEntireFile(lhs.mData, &loaded_size, 0i64, 0i64, 0i64);
    if ( v9 )
    {
      v10 = loaded_size;
      if ( v7 & 1 )
      {
        for ( i = 0i64; i < loaded_size; v10 = loaded_size )
        {
          v9[i] ^= v5[i % v4];
          ++i;
        }
      }
      v12 = SimpleXML::XMLDocument::OpenBuffer(v9, v10);
      v13 = (SimpleXML::XMLDocument *)v12;
      if ( v12 )
      {
        v14 = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v12, "UserOptions", 0i64);
        if ( v14 )
        {
          v15 = v6->mUserOptionGroup;
          for ( j = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v14);
                j;
                j = SimpleXML::XMLDocument::GetNode(v13, 0i64, j) )
          {
            v17 = SimpleXML::XMLNode::GetName(j);
            if ( UFG::qStringCompareInsensitive(v17, "PipelineOptions", -1)
              && (v18 = SimpleXML::XMLNode::GetName(j), UFG::qStringCompareInsensitive(v18, "RunOptions", -1)) )
            {
              v19 = SimpleXML::XMLNode::GetName(j);
              if ( UFG::qStringCompareInsensitive(v19, "Param", -1) )
              {
                v22 = SimpleXML::XMLNode::GetValue(j);
                v23 = SimpleXML::XMLNode::GetName(j);
                UFG::BuildLabOptionGroup::SetOption(v15, v23, v22, 0);
              }
              else
              {
                v20 = SimpleXML::XMLNode::GetAttribute(j, "key");
                v21 = SimpleXML::XMLNode::GetValue(j);
                UFG::BuildLabOptionGroup::SetOption(v15, v20, v21, 0);
              }
            }
            else
            {
              for ( k = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, j);
                    k;
                    k = SimpleXML::XMLDocument::GetNode(v13, 0i64, k) )
              {
                UFG::qString::qString(&lhs);
                v25 = SimpleXML::XMLNode::GetAttribute(k, "name");
                v26 = v25;
                if ( v25 && *v25 )
                {
                  v27 = SimpleXML::XMLNode::GetName(k);
                  v28 = UFG::qString::FormatEx(&v38, "%s.%s", v27, v26);
                  UFG::qString::Set(&lhs, v28->mData, v28->mLength, 0i64, 0);
                  UFG::qString::~qString(&v38);
                }
                else
                {
                  v29 = SimpleXML::XMLNode::GetName(k);
                  UFG::qString::Set(&lhs, v29);
                }
                v30 = SimpleXML::XMLDocument::GetChildNode(v13, "anyType", k);
                if ( v30 )
                {
                  do
                  {
                    v31 = SimpleXML::XMLNode::GetValue(v30);
                    v32 = v31;
                    if ( v31 && *v31 )
                    {
                      v33 = UFG::operator+(&v39, &lhs, ".");
                      UFG::operator+(&result, v33, v32);
                      UFG::qString::~qString(&v39);
                      UFG::BuildLabOptionGroup::SetOption(v15, result.mData, "True", 0);
                      UFG::qString::~qString(&result);
                    }
                    v30 = SimpleXML::XMLDocument::GetNode(v13, 0i64, v30);
                  }
                  while ( v30 );
                }
                else
                {
                  v34 = SimpleXML::XMLNode::GetValue(k);
                  UFG::BuildLabOptionGroup::SetOption(v15, lhs.mData, v34, 0);
                }
                UFG::qString::~qString(&lhs);
              }
            }
          }
        }
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
        UFG::qFreeEntireFile(v9, 0i64);
      }
    }
  }
  UFG::qString::~qString(&lhs);
}

