// File Line: 68
// RVA: 0x1C320
void __fastcall UFG::qBaseTreeVariableRB<unsigned __int64>::Add(UFG::qBaseTreeVariableRB<unsigned __int64> *this, UFG::qBaseNodeVariableRB<unsigned __int64> *x)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v3; // rdi
  unsigned __int64 v4; // rax
  __int64 v5; // rdx
  unsigned __int64 i; // rdx
  BOOL v7; // er9
  signed __int64 v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 *v10; // rdx
  unsigned __int64 *v11; // r8
  unsigned __int64 v12; // r8
  unsigned __int64 *v13; // r8
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rcx
  unsigned __int64 *v16; // rcx
  unsigned __int64 *v17; // r8
  unsigned __int64 v18; // r8
  unsigned __int64 *v19; // r8
  unsigned __int64 v20; // r8

  if ( x )
  {
    v2 = x;
    v3 = this;
    if ( !((_QWORD)x->mParent & 0xFFFFFFFFFFFFFFFEui64) )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::AddHelper(this, x);
      v4 = (_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFEui64;
      v5 = *(_QWORD *)v4;
      v2->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v2->mParent | 1i64);
      for ( i = v5 & 0xFFFFFFFFFFFFFFFEui64; *(_BYTE *)v4 & 1; i = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64 )
      {
        v7 = v4 == *(_QWORD *)(i + 8);
        v8 = 8i64 * (v4 == *(_QWORD *)(i + 8));
        v9 = *(_QWORD **)(v8 + i + 8);
        if ( *(_BYTE *)v9 & 1 )
        {
          *(_QWORD *)v4 &= 0xFFFFFFFFFFFFFFFEui64;
          *v9 &= 0xFFFFFFFFFFFFFFFEui64;
          *(_QWORD *)i |= 1ui64;
          v2 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)i;
        }
        else
        {
          if ( v2 == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v8 + v4 + 8) )
          {
            v2 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4;
            if ( v7 == 1 )
            {
              v10 = *(unsigned __int64 **)(v4 + 16);
              *(_QWORD *)(v4 + 16) = v10[1];
              v11 = (unsigned __int64 *)v10[1];
              if ( v11 != (unsigned __int64 *)&v3->mNULL )
                *v11 = v4 | *(_DWORD *)v11 & 1;
              v12 = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64;
              *v10 = v12 | *(_DWORD *)v10 & 1;
              if ( v4 == *(_QWORD *)(v12 + 8) )
                *(_QWORD *)(v12 + 8) = v10;
              else
                *(_QWORD *)(v12 + 16) = v10;
              v10[1] = v4;
            }
            else
            {
              v10 = *(unsigned __int64 **)(v4 + 8);
              *(_QWORD *)(v4 + 8) = v10[2];
              v13 = (unsigned __int64 *)v10[2];
              if ( &v3->mNULL != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v13 )
                *v13 = v4 | *(_DWORD *)v13 & 1;
              v14 = *(_QWORD *)v4 & 0xFFFFFFFFFFFFFFFEui64;
              *v10 = v14 | *(_DWORD *)v10 & 1;
              if ( v4 == *(_QWORD *)(v14 + 8) )
                *(_QWORD *)(v14 + 8) = v10;
              else
                *(_QWORD *)(v14 + 16) = v10;
              v10[2] = v4;
            }
            v15 = (unsigned __int64)v10 | *(_DWORD *)v4 & 1;
            *(_QWORD *)v4 = v15;
            v4 = v15 & 0xFFFFFFFFFFFFFFFEui64;
            i = *(_QWORD *)(v15 & 0xFFFFFFFFFFFFFFFEui64) & 0xFFFFFFFFFFFFFFFEui64;
          }
          *(_QWORD *)v4 &= 0xFFFFFFFFFFFFFFFEui64;
          *(_QWORD *)i |= 1ui64;
          if ( v7 == 1 )
          {
            v16 = *(unsigned __int64 **)(i + 8);
            *(_QWORD *)(i + 8) = v16[2];
            v17 = (unsigned __int64 *)v16[2];
            if ( &v3->mNULL != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v17 )
              *v17 = i | *(_DWORD *)v17 & 1;
            v18 = *(_QWORD *)i & 0xFFFFFFFFFFFFFFFEui64;
            *v16 = v18 | *(_DWORD *)v16 & 1;
            if ( i == *(_QWORD *)(v18 + 8) )
              *(_QWORD *)(v18 + 8) = v16;
            else
              *(_QWORD *)(v18 + 16) = v16;
            v16[2] = i;
          }
          else
          {
            v16 = *(unsigned __int64 **)(i + 16);
            *(_QWORD *)(i + 16) = v16[1];
            v19 = (unsigned __int64 *)v16[1];
            if ( v19 != (unsigned __int64 *)&v3->mNULL )
              *v19 = i | *(_DWORD *)v19 & 1;
            v20 = *(_QWORD *)i & 0xFFFFFFFFFFFFFFFEui64;
            *v16 = v20 | *(_DWORD *)v16 & 1;
            if ( i == *(_QWORD *)(v20 + 8) )
              *(_QWORD *)(v20 + 8) = v16;
            else
              *(_QWORD *)(v20 + 16) = v16;
            v16[1] = i;
          }
          *(_QWORD *)i = (unsigned __int64)v16 | *(_DWORD *)i & 1;
        }
        v4 = (_QWORD)v2->mParent & 0xFFFFFFFFFFFFFFFEui64;
      }
      v3->mRoot.mChild[0]->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v3->mRoot.mChild[0]->mParent & 0xFFFFFFFFFFFFFFFEui64);
      ++v3->mCount;
    }
  }
}

// File Line: 135
// RVA: 0x1C550
void __fastcall UFG::qBaseTreeVariableRB<unsigned __int64>::AddHelper(UFG::qBaseTreeVariableRB<unsigned __int64> *this, UFG::qBaseNodeVariableRB<unsigned __int64> *z)
{
  UFG::qBaseTreeVariableRB<unsigned __int64> *v2; // r9
  UFG::qBaseTreeVariableRB<unsigned __int64> *i; // r8

  v2 = this;
  z->mChild[0] = &this->mNULL;
  z->mChild[1] = &this->mNULL;
  for ( i = (UFG::qBaseTreeVariableRB<unsigned __int64> *)this->mRoot.mChild[0];
        i != (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mNULL;
        i = (UFG::qBaseTreeVariableRB<unsigned __int64> *)i->mRoot.mChild[i->mRoot.mUID <= z->mUID] )
  {
    v2 = i;
  }
  z->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)v2 | (_QWORD)z->mParent & 1);
  if ( v2 == this || v2->mRoot.mUID > z->mUID )
    v2->mRoot.mChild[0] = z;
  else
    v2->mRoot.mChild[1] = z;
}

// File Line: 279
// RVA: 0x1E2D0
void __fastcall UFG::qBaseTreeVariableRB<unsigned __int64>::RemoveHelper(UFG::qBaseTreeVariableRB<unsigned __int64> *this, UFG::qBaseNodeVariableRB<unsigned __int64> *x)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v3; // r11
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rax
  signed __int64 v5; // r10
  signed __int64 v6; // r9
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rdx
  unsigned __int64 *v9; // r8
  unsigned __int64 v10; // r8
  unsigned __int64 *v11; // r8
  unsigned __int64 v12; // r8
  unsigned __int64 *v13; // r8
  unsigned __int64 *v14; // r9
  unsigned __int64 v15; // r9
  unsigned __int64 *v16; // r9
  unsigned __int64 v17; // r9
  unsigned __int64 v18; // rdx
  unsigned __int64 *v19; // r8
  unsigned __int64 v20; // r8
  unsigned __int64 *v21; // r8
  unsigned __int64 v22; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v23; // rcx

  v2 = this->mRoot.mChild[0];
  v3 = this;
  for ( i = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)x->mParent & 0xFFFFFFFFFFFFFFFEui64);
        !((_QWORD)x->mParent & 1);
        i = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)x->mParent & 0xFFFFFFFFFFFFFFFEui64) )
  {
    if ( v2 == x )
      break;
    if ( x == i->mChild[0] )
    {
      v5 = 1i64;
      v6 = 0i64;
    }
    else
    {
      v5 = 0i64;
      v6 = 1i64;
    }
    v7 = (unsigned __int64)i->mChild[v5];
    if ( *(_BYTE *)v7 & 1 )
    {
      *(_QWORD *)v7 &= 0xFFFFFFFFFFFFFFFEui64;
      i->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)i->mParent | 1i64);
      if ( v5 == 1 )
      {
        v8 = (unsigned __int64)i->mChild[1];
        i->mChild[1] = *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v8 + 8);
        v9 = *(unsigned __int64 **)(v8 + 8);
        if ( v9 != (unsigned __int64 *)&v3->mNULL )
          *v9 = (unsigned __int64)i | *(_DWORD *)v9 & 1;
        v10 = (_QWORD)i->mParent & 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)v8 = v10 | *(_DWORD *)v8 & 1;
        if ( i == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v10 + 8) )
          *(_QWORD *)(v10 + 8) = v8;
        else
          *(_QWORD *)(v10 + 16) = v8;
        *(_QWORD *)(v8 + 8) = i;
      }
      else
      {
        v8 = (unsigned __int64)i->mChild[0];
        i->mChild[0] = *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v8 + 16);
        v11 = *(unsigned __int64 **)(v8 + 16);
        if ( &v3->mNULL != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11 )
          *v11 = (unsigned __int64)i | *(_DWORD *)v11 & 1;
        v12 = (_QWORD)i->mParent & 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)v8 = v12 | *(_DWORD *)v8 & 1;
        if ( i == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v12 + 8) )
          *(_QWORD *)(v12 + 8) = v8;
        else
          *(_QWORD *)(v12 + 16) = v8;
        *(_QWORD *)(v8 + 16) = i;
      }
      i->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v8 | (_QWORD)i->mParent & 1);
      v7 = (unsigned __int64)i->mChild[v5];
    }
    if ( **(_BYTE **)(v7 + 16) & 1 || **(_BYTE **)(v7 + 8) & 1 )
    {
      if ( !(**(_BYTE **)(v7 + 8 * v5 + 8) & 1) )
      {
        **(_QWORD **)(v7 + 8 * v6 + 8) &= 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)v7 |= 1ui64;
        if ( v5 == 1 )
        {
          v13 = *(unsigned __int64 **)(v7 + 8);
          *(_QWORD *)(v7 + 8) = v13[2];
          v14 = (unsigned __int64 *)v13[2];
          if ( &v3->mNULL != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v14 )
            *v14 = v7 | *(_DWORD *)v14 & 1;
          v15 = *(_QWORD *)v7 & 0xFFFFFFFFFFFFFFFEui64;
          *v13 = v15 | *(_DWORD *)v13 & 1;
          if ( v7 == *(_QWORD *)(v15 + 8) )
            *(_QWORD *)(v15 + 8) = v13;
          else
            *(_QWORD *)(v15 + 16) = v13;
          v13[2] = v7;
        }
        else
        {
          v13 = *(unsigned __int64 **)(v7 + 16);
          *(_QWORD *)(v7 + 16) = v13[1];
          v16 = (unsigned __int64 *)v13[1];
          if ( v16 != (unsigned __int64 *)&v3->mNULL )
            *v16 = v7 | *(_DWORD *)v16 & 1;
          v17 = *(_QWORD *)v7 & 0xFFFFFFFFFFFFFFFEui64;
          *v13 = v17 | *(_DWORD *)v13 & 1;
          if ( v7 == *(_QWORD *)(v17 + 8) )
            *(_QWORD *)(v17 + 8) = v13;
          else
            *(_QWORD *)(v17 + 16) = v13;
          v13[1] = v7;
        }
        *(_QWORD *)v7 = (unsigned __int64)v13 | *(_DWORD *)v7 & 1;
        v7 = (unsigned __int64)i->mChild[v5];
      }
      *(_QWORD *)v7 ^= (*(_DWORD *)v7 ^ LODWORD(i->mParent)) & 1;
      i->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)i->mParent & 0xFFFFFFFFFFFFFFFEui64);
      **(_QWORD **)(v7 + 8 * v5 + 8) &= 0xFFFFFFFFFFFFFFFEui64;
      if ( v5 == 1 )
      {
        v18 = (unsigned __int64)i->mChild[1];
        i->mChild[1] = *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v18 + 8);
        v19 = *(unsigned __int64 **)(v18 + 8);
        if ( v19 != (unsigned __int64 *)&v3->mNULL )
          *v19 = (unsigned __int64)i | *(_DWORD *)v19 & 1;
        v20 = (_QWORD)i->mParent & 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)v18 = v20 | *(_DWORD *)v18 & 1;
        if ( i == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v20 + 8) )
          *(_QWORD *)(v20 + 8) = v18;
        else
          *(_QWORD *)(v20 + 16) = v18;
        *(_QWORD *)(v18 + 8) = i;
      }
      else
      {
        v18 = (unsigned __int64)i->mChild[0];
        i->mChild[0] = *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v18 + 16);
        v21 = *(unsigned __int64 **)(v18 + 16);
        if ( &v3->mNULL != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v21 )
          *v21 = (unsigned __int64)i | *(_DWORD *)v21 & 1;
        v22 = (_QWORD)i->mParent & 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)v18 = v22 | *(_DWORD *)v18 & 1;
        if ( i == *(UFG::qBaseNodeVariableRB<unsigned __int64> **)(v22 + 8) )
          *(_QWORD *)(v22 + 8) = v18;
        else
          *(_QWORD *)(v22 + 16) = v18;
        *(_QWORD *)(v18 + 16) = i;
      }
      v23 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v18 | (_QWORD)i->mParent & 1);
      x = v2;
      i->mParent = v23;
    }
    else
    {
      *(_QWORD *)v7 |= 1ui64;
      x = i;
    }
  }
  x->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)x->mParent & 0xFFFFFFFFFFFFFFFEui64);
}

