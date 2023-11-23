// File Line: 146
// RVA: 0x198360
char __fastcall UFG::CommandManager::ExecuteCommand(UFG::CommandManager *this, const char *command_name)
{
  unsigned __int64 v3; // rax
  UFG::qTree64Base *v4; // rax
  char *mNeighbours; // rbx
  char v6; // bl
  void **v8; // [rsp+30h] [rbp-58h] BYREF
  UFG::qBaseTreeRB v9; // [rsp+38h] [rbp-50h] BYREF
  int v10; // [rsp+90h] [rbp+8h] BYREF
  UFG::qBaseTreeRB *v11; // [rsp+A0h] [rbp+18h]

  v3 = UFG::qStringHashUpper64(command_name, 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qTree64Base::Get(&this->mCommands.mTree, v3);
  if ( !v4 )
    return 0;
  mNeighbours = (char *)v4[-1].mHead.mNeighbours;
  if ( v4 == (UFG::qTree64Base *)24 )
    return 0;
  v10 = 0;
  v8 = &UFG::CommandContext::`vftable;
  v11 = &v9;
  UFG::qBaseTreeRB::qBaseTreeRB(&v9);
  if ( (*(unsigned int (__fastcall **)(char *, void ***, int *))(*(_QWORD *)mNeighbours + 8i64))(mNeighbours, &v8, &v10) == 1 )
  {
    (*(void (__fastcall **)(char *, void ***))(*(_QWORD *)mNeighbours + 16i64))(mNeighbours, &v8);
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
  unsigned __int64 v3; // rax
  UFG::CommandKeyBindingMap *mActiveBindingMap; // rcx

  v3 = UFG::qStringHashUpper64(mapName, 0xFFFFFFFFFFFFFFFFui64);
  mActiveBindingMap = this->mActiveBindingMap;
  if ( !mActiveBindingMap || mActiveBindingMap->mBaseNode.mUID != v3 )
    this->mActiveBindingMap = (UFG::CommandKeyBindingMap *)UFG::qTree64Base::Get(&this->mBindingMaps.mTree, v3);
}

// File Line: 254
// RVA: 0x1986C0
void __fastcall UFG::CommandManager::GetCommandsFromTags(
        UFG::CommandManager *this,
        UFG::qList<UFG::qString,UFG::qString,1,0> *tags,
        UFG::qArray<UFG::Command *,0> *commands)
{
  UFG::qString *mNext; // rax
  UFG::CommandManager *v5; // r8
  __int64 *p_mCount; // rcx
  UFG::Command *p_mNext; // r15
  UFG::qString *v8; // r13
  __int64 size; // rbp
  __int64 v10; // rax
  unsigned int capacity; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::Command **v16; // r14
  __int64 i; // r9
  __int64 v18; // r8
  UFG::Command **p; // rax
  __int64 *v20; // [rsp+20h] [rbp-48h]
  UFG::qList<UFG::qString,UFG::qString,1,0> *v22; // [rsp+78h] [rbp+10h]
  UFG::qString *v23; // [rsp+88h] [rbp+20h]

  v22 = tags;
  mNext = (UFG::qString *)tags->mNode.mNext;
  v5 = this;
  v23 = mNext;
  if ( mNext != (UFG::qString *)tags )
  {
    p_mCount = &this[-1].mBindingMaps.mTree.mCount;
    v20 = p_mCount;
    do
    {
      p_mNext = (UFG::Command *)&v5->mCommandList.mNode.mNext[-1].mNext;
      if ( p_mNext != (UFG::Command *)p_mCount )
      {
        do
        {
          v8 = (UFG::qString *)p_mNext->mTags.mNode.mNext;
          if ( v8 != (UFG::qString *)&p_mNext->mTags )
          {
            do
            {
              if ( UFG::qString::operator==(v8, mNext) )
              {
                size = commands->size;
                v10 = 0i64;
                if ( !(_DWORD)size )
                  goto LABEL_11;
                while ( p_mNext != commands->p[v10] )
                {
                  v10 = (unsigned int)(v10 + 1);
                  if ( (unsigned int)v10 >= (unsigned int)size )
                    goto LABEL_11;
                }
                if ( (_DWORD)v10 == -1 )
                {
LABEL_11:
                  capacity = commands->capacity;
                  v12 = size + 1;
                  if ( (int)size + 1 > capacity )
                  {
                    if ( capacity )
                      v13 = 2 * capacity;
                    else
                      v13 = 1;
                    for ( ; v13 < v12; v13 *= 2 )
                      ;
                    if ( v13 <= 2 )
                      v13 = 2;
                    if ( v13 - v12 > 0x10000 )
                      v13 = size + 65537;
                    if ( v13 != (_DWORD)size )
                    {
                      v14 = 8i64 * v13;
                      if ( !is_mul_ok(v13, 8ui64) )
                        v14 = -1i64;
                      v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
                      v16 = (UFG::Command **)v15;
                      if ( commands->p )
                      {
                        for ( i = 0i64;
                              (unsigned int)i < commands->size;
                              v15[v18] = (UFG::allocator::free_link)commands->p[v18] )
                        {
                          v18 = i;
                          i = (unsigned int)(i + 1);
                        }
                        operator delete[](commands->p);
                      }
                      commands->p = v16;
                      commands->capacity = v13;
                    }
                  }
                  p = commands->p;
                  commands->size = v12;
                  p[size] = p_mNext;
                }
              }
              v8 = (UFG::qString *)v8->mNext;
              mNext = v23;
            }
            while ( v8 != (UFG::qString *)&p_mNext->mTags );
            p_mCount = v20;
          }
          p_mNext = (UFG::Command *)&p_mNext->mNext[-1].mNext;
        }
        while ( p_mNext != (UFG::Command *)p_mCount );
        tags = v22;
        v5 = this;
      }
      mNext = (UFG::qString *)mNext->mNext;
      v23 = mNext;
    }
    while ( mNext != (UFG::qString *)tags );
  }
}

// File Line: 271
// RVA: 0x1984F0
bool __fastcall UFG::CommandManager::GetCommandsByTag(
        UFG::CommandManager *this,
        const char *tag,
        UFG::qArray<UFG::Command *,0> *commands)
{
  UFG::qNode<UFG::Command,UFG::Command> *mNext; // r15
  __int64 *p_mCount; // rcx
  UFG::Command *p_mNext; // r15
  const char *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // r13
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mTags; // r14
  __int64 size; // rbp
  int v11; // eax
  unsigned int capacity; // ebx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::Command **v17; // r14
  unsigned int j; // r9d
  __int64 v19; // rcx
  UFG::Command **p; // rax
  __int64 *i; // [rsp+60h] [rbp+8h]

  mNext = this->mCommandList.mNode.mNext;
  p_mCount = &this[-1].mBindingMaps.mTree.mCount;
  p_mNext = (UFG::Command *)&mNext[-1].mNext;
  v7 = tag;
  for ( i = p_mCount; p_mNext != (UFG::Command *)p_mCount; p_mNext = (UFG::Command *)&p_mNext->mNext[-1].mNext )
  {
    v8 = p_mNext->mTags.mNode.mNext;
    p_mTags = &p_mNext->mTags;
    if ( v8 != (UFG::qNode<UFG::qString,UFG::qString> *)&p_mNext->mTags )
    {
      do
      {
        if ( !(unsigned int)UFG::qStringCompare((const char *)v8[1].mNext, v7, -1) )
        {
          size = commands->size;
          v11 = 0;
          if ( !(_DWORD)size )
            goto LABEL_9;
          while ( p_mNext != commands->p[v11] )
          {
            if ( ++v11 >= (unsigned int)size )
              goto LABEL_9;
          }
          if ( v11 == -1 )
          {
LABEL_9:
            capacity = commands->capacity;
            v13 = size + 1;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v14 = 2 * capacity;
              else
                v14 = 1;
              for ( ; v14 < v13; v14 *= 2 )
                ;
              if ( v14 <= 2 )
                v14 = 2;
              if ( v14 - v13 > 0x10000 )
                v14 = size + 65537;
              if ( v14 != (_DWORD)size )
              {
                v15 = 8i64 * v14;
                if ( !is_mul_ok(v14, 8ui64) )
                  v15 = -1i64;
                v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
                v17 = (UFG::Command **)v16;
                if ( commands->p )
                {
                  for ( j = 0; j < commands->size; v16[v19] = (UFG::allocator::free_link)commands->p[v19] )
                    v19 = j++;
                  operator delete[](commands->p);
                }
                commands->p = v17;
                commands->capacity = v14;
                p_mTags = &p_mNext->mTags;
              }
            }
            p = commands->p;
            commands->size = v13;
            p[size] = p_mNext;
          }
        }
        v8 = v8->mNext;
        v7 = tag;
      }
      while ( v8 != (UFG::qNode<UFG::qString,UFG::qString> *)p_mTags );
      p_mCount = i;
    }
  }
  return commands->size != 0;
}

