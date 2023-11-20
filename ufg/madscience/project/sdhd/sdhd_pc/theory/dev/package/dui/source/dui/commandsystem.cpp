// File Line: 146
// RVA: 0x198360
char __fastcall UFG::CommandManager::ExecuteCommand(UFG::CommandManager *this, const char *command_name)
{
  UFG::CommandManager *v2; // rbx
  unsigned __int64 v3; // rax
  UFG::qTree64Base *v4; // rax
  signed __int64 v5; // rbx
  char v6; // bl
  void **v8; // [rsp+30h] [rbp-58h]
  UFG::qBaseTreeRB v9; // [rsp+38h] [rbp-50h]
  int v10; // [rsp+90h] [rbp+8h]
  UFG::qBaseTreeRB *v11; // [rsp+A0h] [rbp+18h]

  v2 = this;
  v3 = UFG::qStringHashUpper64(command_name, 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qTree64Base::Get(&v2->mCommands.mTree, v3);
  if ( !v4 )
    return 0;
  v5 = (signed __int64)v4[-1].mHead.mNeighbours;
  if ( v4 == (UFG::qTree64Base *)24 )
    return 0;
  v10 = 0;
  v8 = &UFG::CommandContext::`vftable;
  v11 = &v9;
  UFG::qBaseTreeRB::qBaseTreeRB(&v9);
  if ( (*(unsigned int (__fastcall **)(signed __int64, void ***, int *))(*(_QWORD *)v5 + 8i64))(v5, &v8, &v10) == 1 )
  {
    (*(void (__fastcall **)(signed __int64, void ***))(*(_QWORD *)v5 + 16i64))(v5, &v8);
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  v8 = &UFG::CommandContext::`vftable;
  v11 = &v9;
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1>::DeleteAll((UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *)&v9);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v9);
  return v6;
}

// File Line: 229
// RVA: 0x19D600
void __fastcall UFG::CommandManager::SetActiveBindingMap(UFG::CommandManager *this, const char *mapName)
{
  UFG::CommandManager *v2; // rbx
  unsigned __int64 v3; // rax
  UFG::CommandKeyBindingMap *v4; // rcx

  v2 = this;
  v3 = UFG::qStringHashUpper64(mapName, 0xFFFFFFFFFFFFFFFFui64);
  v4 = v2->mActiveBindingMap;
  if ( !v4 || v4->mBaseNode.mUID != v3 )
    v2->mActiveBindingMap = (UFG::CommandKeyBindingMap *)UFG::qTree64Base::Get(&v2->mBindingMaps.mTree, v3);
}

// File Line: 254
// RVA: 0x1986C0
void __fastcall UFG::CommandManager::GetCommandsFromTags(UFG::CommandManager *this, UFG::qList<UFG::qString,UFG::qString,1,0> *tags, UFG::qArray<UFG::Command *,0> *commands)
{
  UFG::qString *v3; // rax
  UFG::qArray<UFG::Command *,0> *v4; // rdi
  UFG::CommandManager *v5; // r8
  __int64 *v6; // rcx
  signed __int64 v7; // r15
  UFG::qString *v8; // r13
  __int64 v9; // rbp
  __int64 v10; // rax
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::Command **v16; // r14
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  UFG::Command **v19; // rax
  __int64 *v20; // [rsp+20h] [rbp-48h]
  UFG::CommandManager *v21; // [rsp+70h] [rbp+8h]
  UFG::qList<UFG::qString,UFG::qString,1,0> *v22; // [rsp+78h] [rbp+10h]
  UFG::qString *v23; // [rsp+88h] [rbp+20h]

  v22 = tags;
  v21 = this;
  v3 = (UFG::qString *)tags->mNode.mNext;
  v4 = commands;
  v5 = this;
  v23 = v3;
  if ( v3 != (UFG::qString *)tags )
  {
    v6 = &this[-1].mBindingMaps.mTree.mCount;
    v20 = v6;
    do
    {
      v7 = (signed __int64)&v5->mCommandList.mNode.mNext[-1].mNext;
      if ( (__int64 *)v7 != v6 )
      {
        do
        {
          v8 = *(UFG::qString **)(v7 + 160);
          if ( v8 != (UFG::qString *)(v7 + 152) )
          {
            do
            {
              if ( UFG::qString::operator==(v8, v3) )
              {
                v9 = v4->size;
                v10 = 0i64;
                if ( !(_DWORD)v9 )
                  goto LABEL_11;
                while ( (UFG::Command *)v7 != v4->p[v10] )
                {
                  v10 = (unsigned int)(v10 + 1);
                  if ( (unsigned int)v10 >= (unsigned int)v9 )
                    goto LABEL_11;
                }
                if ( (_DWORD)v10 == -1 )
                {
LABEL_11:
                  v11 = v4->capacity;
                  v12 = v9 + 1;
                  if ( (signed int)v9 + 1 > v11 )
                  {
                    if ( v11 )
                      v13 = 2 * v11;
                    else
                      v13 = 1;
                    for ( ; v13 < v12; v13 *= 2 )
                      ;
                    if ( v13 <= 2 )
                      v13 = 2;
                    if ( v13 - v12 > 0x10000 )
                      v13 = v9 + 65537;
                    if ( v13 != (_DWORD)v9 )
                    {
                      v14 = 8i64 * v13;
                      if ( !is_mul_ok(v13, 8ui64) )
                        v14 = -1i64;
                      v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
                      v16 = (UFG::Command **)v15;
                      if ( v4->p )
                      {
                        v17 = 0i64;
                        if ( v4->size )
                        {
                          do
                          {
                            v18 = v17;
                            v17 = (unsigned int)(v17 + 1);
                            v15[v18] = (UFG::allocator::free_link)v4->p[v18];
                          }
                          while ( (unsigned int)v17 < v4->size );
                        }
                        operator delete[](v4->p);
                      }
                      v4->p = v16;
                      v4->capacity = v13;
                    }
                  }
                  v19 = v4->p;
                  v4->size = v12;
                  v19[v9] = (UFG::Command *)v7;
                }
              }
              v8 = (UFG::qString *)v8->mNext;
              v3 = v23;
            }
            while ( v8 != (UFG::qString *)(v7 + 152) );
            v6 = v20;
          }
          v7 = *(_QWORD *)(v7 + 16) - 8i64;
        }
        while ( (__int64 *)v7 != v6 );
        tags = v22;
        v5 = v21;
      }
      v3 = (UFG::qString *)v3->mNext;
      v23 = v3;
    }
    while ( v3 != (UFG::qString *)tags );
  }
}

// File Line: 271
// RVA: 0x1984F0
bool __fastcall UFG::CommandManager::GetCommandsByTag(UFG::CommandManager *this, const char *tag, UFG::qArray<UFG::Command *,0> *commands)
{
  UFG::qNode<UFG::Command,UFG::Command> *v3; // r15
  __int64 *v4; // rcx
  signed __int64 v5; // r15
  UFG::qArray<UFG::Command *,0> *v6; // rdi
  const char *v7; // rax
  __int64 v8; // r13
  signed __int64 v9; // r14
  __int64 v10; // rbp
  int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::Command **v17; // r14
  unsigned int j; // er9
  __int64 v19; // rcx
  UFG::Command **v20; // rax
  __int64 *i; // [rsp+60h] [rbp+8h]
  const char *v23; // [rsp+68h] [rbp+10h]

  v23 = tag;
  v3 = this->mCommandList.mNode.mNext;
  v4 = &this[-1].mBindingMaps.mTree.mCount;
  v5 = (signed __int64)&v3[-1].mNext;
  v6 = commands;
  v7 = tag;
  for ( i = v4; (__int64 *)v5 != v4; v5 = *(_QWORD *)(v5 + 16) - 8i64 )
  {
    v8 = *(_QWORD *)(v5 + 160);
    v9 = v5 + 152;
    if ( v8 != v5 + 152 )
    {
      do
      {
        if ( !(unsigned int)UFG::qStringCompare(*(const char **)(v8 + 24), v7, -1) )
        {
          v10 = v6->size;
          v11 = 0;
          if ( !(_DWORD)v10 )
            goto LABEL_9;
          while ( (UFG::Command *)v5 != v6->p[v11] )
          {
            if ( ++v11 >= (unsigned int)v10 )
              goto LABEL_9;
          }
          if ( v11 == -1 )
          {
LABEL_9:
            v12 = v6->capacity;
            v13 = v10 + 1;
            if ( (signed int)v10 + 1 > v12 )
            {
              if ( v12 )
                v14 = 2 * v12;
              else
                v14 = 1;
              for ( ; v14 < v13; v14 *= 2 )
                ;
              if ( v14 <= 2 )
                v14 = 2;
              if ( v14 - v13 > 0x10000 )
                v14 = v10 + 65537;
              if ( v14 != (_DWORD)v10 )
              {
                v15 = 8i64 * v14;
                if ( !is_mul_ok(v14, 8ui64) )
                  v15 = -1i64;
                v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
                v17 = (UFG::Command **)v16;
                if ( v6->p )
                {
                  for ( j = 0; j < v6->size; v16[v19] = (UFG::allocator::free_link)v6->p[v19] )
                    v19 = j++;
                  operator delete[](v6->p);
                }
                v6->p = v17;
                v6->capacity = v14;
                v9 = v5 + 152;
              }
            }
            v20 = v6->p;
            v6->size = v13;
            v20[v10] = (UFG::Command *)v5;
          }
        }
        v8 = *(_QWORD *)(v8 + 8);
        v7 = v23;
      }
      while ( v8 != v9 );
      v4 = i;
    }
  }
  return v6->size > 0;
}

