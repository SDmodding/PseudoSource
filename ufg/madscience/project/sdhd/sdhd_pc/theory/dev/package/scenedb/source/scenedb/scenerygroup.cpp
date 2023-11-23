// File Line: 31
// RVA: 0x233A40
void __fastcall UFG::SceneryGroup::MakeInvisible(UFG::SceneryGroup *this, unsigned int cullIndex)
{
  __int64 mOffset; // rax
  char *v3; // r8
  char *v4; // r9
  __int64 v5; // rax

  mOffset = this->mCullInfo.mOffset;
  v3 = 0i64;
  if ( mOffset )
    v4 = (char *)&this->mCullInfo + mOffset;
  else
    v4 = 0i64;
  *(_WORD *)&v4[64 * (unsigned __int64)cullIndex + 30] = -1;
  v5 = this->mInstances.mOffset;
  if ( v5 )
    v3 = (char *)&this->mInstances + v5;
  v3[96 * cullIndex + 8] |= 0x20u;
  Render::IDecalScenery::RemoveAttachedDecals(this->mRenderComponent, cullIndex);
}

// File Line: 43
// RVA: 0x233990
void UFG::SceneryGroup::MakeAllVisible(void)
{
  UFG::qBaseTreeRB *i; // r9
  unsigned int j; // ecx
  UFG::qBaseNodeRB *mParent; // rax
  char *v3; // r8
  char *v4; // rax
  UFG::qBaseNodeRB *v5; // r8
  char *v6; // r10

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9A90);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9A90, &i->mRoot) )
  {
    for ( j = 0; j < WORD1(i[1].mRoot.mChild[1]); ++j )
    {
      mParent = i[1].mNULL.mParent;
      if ( mParent )
        v3 = (char *)&i[1].mNULL + (_QWORD)mParent;
      else
        v3 = 0i64;
      v4 = &v3[96 * j];
      if ( (v4[8] & 0x20) != 0 )
      {
        v5 = i[1].mNULL.mChild[0];
        if ( v5 )
          v6 = (char *)i[1].mNULL.mChild + (_QWORD)v5;
        else
          v6 = 0i64;
        *(_WORD *)&v6[64 * (unsigned __int64)j + 30] = 0;
        v4[8] &= ~0x20u;
      }
    }
  }
}

// File Line: 66
// RVA: 0x231410
void __fastcall UFG::SceneryGroup::DrawStatic(
        _QWORD *sceneryGroup_Remote,
        Render::View *view,
        char *pTransparencyState)
{
  unsigned int v3; // edi
  char *v5; // rbx
  Illusion::StateValues *StateValues; // rax
  int mCullIndex; // r9d
  bool v9; // r13
  bool v10; // r12
  __int64 v11; // rbp
  char *v12; // rsi
  _DWORD *v13; // rdi
  char *v14; // rax
  char *v15; // rdx
  __int64 v16; // rax
  char *v17; // rcx
  __int64 v18; // rax
  Illusion::StateValues *v19; // [rsp+60h] [rbp+8h]

  v3 = *((unsigned __int16 *)sceneryGroup_Remote + 45);
  v5 = (char *)sceneryGroup_Remote + sceneryGroup_Remote[13] + 104;
  StateValues = Render::View::GetStateValues(view);
  mCullIndex = view->mSettings->mCullIndex;
  v19 = StateValues;
  v9 = mCullIndex == -1;
  v10 = mCullIndex != 0;
  if ( v3 )
  {
    v11 = v3;
    do
    {
      v12 = v5;
      v5 += 96;
      if ( *((_QWORD *)v12 + 2) )
      {
        v13 = (_DWORD *)((char *)&sceneryGroup_Remote[4 * *((unsigned __int16 *)v12 + 2) + 16] + sceneryGroup_Remote[16]);
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
          v17 = &v12[v16 + 16];
          if ( v17 )
          {
            v18 = 16i64;
            if ( (v12[8] & 0x10) != 0 && v10 )
              v18 = 48i64;
            Render::View::Draw(view, (Illusion::ModelHandle *)&v17[v18], (UFG::qMatrix44 *)(v12 + 32), v9, 0i64);
          }
        }
      }
      --v11;
    }
    while ( v11 );
  }
}

