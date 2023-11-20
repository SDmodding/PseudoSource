// File Line: 31
// RVA: 0x233A40
void __fastcall UFG::SceneryGroup::MakeInvisible(UFG::SceneryGroup *this, unsigned int cullIndex)
{
  __int64 v2; // rax
  char *v3; // r8
  char *v4; // r9
  __int64 v5; // rax

  v2 = this->mCullInfo.mOffset;
  v3 = 0i64;
  if ( v2 )
    v4 = (char *)&this->mCullInfo + v2;
  else
    v4 = 0i64;
  *(_WORD *)&v4[64 * (unsigned __int64)cullIndex + 30] = -1;
  v5 = this->mInstances.mOffset;
  if ( v5 )
    v3 = (char *)&this->mInstances + v5;
  v3[96 * cullIndex + 8] |= 0x20u;
  Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&this->mRenderComponent->vfptr, cullIndex);
}

// File Line: 43
// RVA: 0x233990
void UFG::SceneryGroup::MakeAllVisible(void)
{
  UFG::qBaseTreeRB *i; // r9
  unsigned int v1; // ecx
  UFG::qBaseNodeRB *v2; // rax
  signed __int64 v3; // r8
  signed __int64 v4; // rax
  UFG::qBaseNodeRB *v5; // r8
  signed __int64 v6; // r10

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9A90);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9A90, &i->mRoot) )
  {
    v1 = 0;
    if ( WORD1(i[1].mRoot.mChild[1]) > 0u )
    {
      do
      {
        v2 = i[1].mNULL.mParent;
        if ( v2 )
          v3 = (signed __int64)&i[1].mNULL + (_QWORD)v2;
        else
          v3 = 0i64;
        v4 = v3 + 96i64 * v1;
        if ( *(_BYTE *)(v4 + 8) & 0x20 )
        {
          v5 = i[1].mNULL.mChild[0];
          if ( v5 )
            v6 = (signed __int64)i[1].mNULL.mChild + (_QWORD)v5;
          else
            v6 = 0i64;
          *(_WORD *)(((unsigned __int64)v1 << 6) + v6 + 30) = 0;
          *(_BYTE *)(v4 + 8) &= 0xDFu;
        }
        ++v1;
      }
      while ( v1 < WORD1(i[1].mRoot.mChild[1]) );
    }
  }
}

// File Line: 66
// RVA: 0x231410
void __fastcall UFG::SceneryGroup::DrawStatic(void *sceneryGroup_Remote, Render::View *view, char *pTransparencyState)
{
  unsigned int v3; // edi
  _QWORD *v4; // r15
  char *v5; // rbx
  Render::View *v6; // r14
  Illusion::StateValues *v7; // rax
  int v8; // er9
  bool v9; // r13
  bool v10; // r12
  __int64 v11; // rbp
  char *v12; // rsi
  _DWORD *v13; // rdi
  char *v14; // rax
  char *v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rcx
  signed __int64 v18; // rax
  Illusion::StateValues *v19; // [rsp+60h] [rbp+8h]

  v3 = *((unsigned __int16 *)sceneryGroup_Remote + 45);
  v4 = sceneryGroup_Remote;
  v5 = (char *)sceneryGroup_Remote + *((_QWORD *)sceneryGroup_Remote + 13) + 104;
  v6 = view;
  v7 = Render::View::GetStateValues(view);
  v8 = v6->mSettings->mCullIndex;
  v19 = v7;
  v9 = v8 == -1;
  v10 = v8 != 0;
  if ( v3 )
  {
    v11 = v3;
    do
    {
      v12 = v5;
      v5 += 96;
      if ( *((_QWORD *)v12 + 2) )
      {
        v13 = (_DWORD *)((char *)&v4[4 * (*((unsigned __int16 *)v12 + 2) + 4i64)] + v4[16]);
        v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
        *(_DWORD *)v14 = *v13;
        v15 = v14;
        *((_DWORD *)v14 + 1) = v13[1];
        *((_DWORD *)v14 + 2) = v13[2];
        *((_DWORD *)v14 + 3) = v13[3];
        *((_DWORD *)v14 + 4) = v13[4];
        *((_DWORD *)v14 + 5) = v13[5];
        *((_DWORD *)v14 + 6) = v13[6];
        *((_DWORD *)v14 + 7) = v13[7];
        *((_DWORD *)v14 + 8) = v13[8];
        *((_DWORD *)v14 + 9) = v13[9];
        *((_DWORD *)v14 + 10) = v13[10];
        *((_DWORD *)v14 + 11) = v13[11];
        *((_DWORD *)v14 + 12) = v13[12];
        *((_DWORD *)v14 + 13) = v13[13];
        *((_DWORD *)v14 + 14) = v13[14];
        *((_DWORD *)v14 + 15) = v13[15];
        v19->mSetValueMask.mFlags[0] |= 0x400000000ui64;
        v16 = *((_QWORD *)v12 + 2);
        v19->mParamValues[34] = v15;
        if ( v16 )
        {
          v17 = (signed __int64)&v12[v16 + 16];
          if ( v17 )
          {
            v18 = 16i64;
            if ( v12[8] & 0x10 )
            {
              if ( v10 )
                v18 = 48i64;
            }
            Render::View::Draw(v6, (Illusion::ModelHandle *)(v18 + v17), (UFG::qMatrix44 *)(v12 + 32), v9);
          }
        }
      }
      --v11;
    }
    while ( v11 );
  }
}

