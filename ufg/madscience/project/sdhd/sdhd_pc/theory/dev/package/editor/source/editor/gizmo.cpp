// File Line: 24
// RVA: 0x146DB50
__int64 UFG::Editor::_dynamic_initializer_for__gTransformationChangedChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gTransformationChangedChannel, 0x65C2B07Bu, 0i64, 0i64);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gTransformationChangedChannel__);
}

// File Line: 363
// RVA: 0x208470
UFG::qMatrix44 *__fastcall UFG::Editor::Gizmo::DetermineTransform(UFG::Editor::Gizmo *this, UFG::qMatrix44 *result)
{
  float v2; // eax
  float v3; // xmm1_4
  UFG::qMatrix44 *v4; // r15
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // eax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // eax
  float v14; // xmm2_4
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v15; // r13
  signed int v16; // edx
  UFG::Editor::GizmoLocation v17; // ecx
  int v18; // ecx
  float v19; // xmm0_4
  unsigned int v20; // er12
  __int64 v21; // r14
  float *v22; // rbx
  __int64 v23; // rbp
  char *v24; // rdi
  UFG::Editor::FnObject *v25; // rax
  UFG::Editor::FnModifier *v26; // rax
  __int64 v27; // rax
  UFG::qString *v28; // rdx
  float v29; // xmm1_4
  float v30; // xmm0_4
  UFG::qVector4 v31; // xmm1
  UFG::qVector4 v32; // xmm2
  UFG::qVector4 v33; // xmm3
  float v34; // xmm0_4
  float v35; // xmm0_4
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v36; // rsi
  UFG::Editor::FnObject *v37; // rax
  UFG::Editor::FnModifier *v38; // rax
  __int64 v39; // rax
  __int64 v40; // rcx
  UFG::qString *v41; // rsi
  UFG::Editor::DAGPath *v42; // rbx
  UFG::Editor::FnObject *v43; // rax
  UFG::Editor::FnModifier *v44; // rax
  UFG::qVector3 center; // [rsp+20h] [rbp-378h]
  char v47; // [rsp+30h] [rbp-368h]
  int v48; // [rsp+60h] [rbp-338h]
  float v49; // [rsp+64h] [rbp-334h]
  float v50; // [rsp+68h] [rbp-330h]
  UFG::qVector3 points; // [rsp+70h] [rbp-328h]
  float radius; // [rsp+3A0h] [rbp+8h]

  v2 = this->mTransform.v0.x;
  v3 = this->mTransform.v0.z;
  v4 = result;
  v5 = this->mTransform.v0.w;
  result->v0.y = this->mTransform.v0.y;
  result->v0.z = v3;
  result->v0.x = v2;
  result->v0.w = v5;
  v6 = this->mTransform.v1.z;
  v7 = this->mTransform.v1.x;
  v8 = this->mTransform.v1.w;
  result->v1.y = this->mTransform.v1.y;
  result->v1.z = v6;
  result->v1.x = v7;
  result->v1.w = v8;
  v9 = this->mTransform.v2.z;
  v10 = this->mTransform.v2.x;
  v11 = this->mTransform.v2.w;
  result->v2.y = this->mTransform.v2.y;
  result->v2.z = v9;
  result->v2.x = v10;
  result->v2.w = v11;
  v12 = this->mTransform.v3.z;
  v13 = this->mTransform.v3.x;
  v14 = this->mTransform.v3.w;
  result->v3.y = this->mTransform.v3.y;
  result->v3.z = v12;
  result->v3.x = v13;
  result->v3.w = v14;
  v15 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v16 = (signed int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  if ( !v16 )
    return v4;
  v17 = this->mLocationMode;
  if ( v17 == GizmoLocation_LastSelected )
  {
    v42 = (UFG::Editor::DAGPath *)((char *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev
                                 + 88 * (unsigned int)(v16 - 1));
    v43 = UFG::Editor::DAGPath::GetFnObject(v42);
    if ( !v43 )
      return v4;
    v44 = UFG::Editor::FnObject::GetModifier(v43, &v42->mInterfaceName);
    if ( !v44 )
      return v4;
    v39 = (__int64)v44->vfptr->Gizmo(v44);
    v40 = v39;
    if ( !v39 )
      return v4;
    if ( v42->mSubElements.size )
    {
      v41 = v42->mSubElements.p;
      goto LABEL_30;
    }
LABEL_29:
    v41 = &UFG::Editor::DAGPath::sEmtpyString;
    goto LABEL_30;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    v36 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
    v37 = UFG::Editor::DAGPath::GetFnObject((UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev);
    if ( !v37 )
      return v4;
    v38 = UFG::Editor::FnObject::GetModifier(v37, (UFG::qSymbol *)&v36[3].mNext);
    if ( !v38 )
      return v4;
    v39 = (__int64)v38->vfptr->Gizmo(v38);
    v40 = v39;
    if ( !v39 )
      return v4;
    if ( LODWORD(v36[4].mPrev) )
    {
      v41 = (UFG::qString *)v36[4].mNext;
LABEL_30:
      (*(void (__fastcall **)(__int64, char *, UFG::qMatrix44 *))(*(_QWORD *)v39 + 8i64))(v40, v41->mData, v4);
      return v4;
    }
    goto LABEL_29;
  }
  if ( v18 == 1 )
  {
    v19 = (float)v16;
    if ( (float)v16 >= 64.0 )
      v19 = FLOAT_64_0;
    v20 = (signed int)v19;
    if ( (signed int)v19 )
    {
      v21 = 0i64;
      v22 = &points.z;
      v23 = v20;
      do
      {
        v24 = (char *)v15[4].mPrev + v21;
        v25 = UFG::Editor::DAGPath::GetFnObject((UFG::Editor::DAGPath *)((char *)v15[4].mPrev + v21));
        if ( v25
          && (v26 = UFG::Editor::FnObject::GetModifier(v25, (UFG::qSymbol *)v24 + 14)) != 0i64
          && (v27 = (__int64)v26->vfptr->Gizmo(v26)) != 0 )
        {
          if ( *((_DWORD *)v24 + 16) )
            v28 = (UFG::qString *)*((_QWORD *)v24 + 9);
          else
            v28 = &UFG::Editor::DAGPath::sEmtpyString;
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 8i64))(v27, v28->mData, &v47);
          v29 = v49;
          *((_DWORD *)v22 - 2) = v48;
          v30 = v50;
        }
        else
        {
          v29 = UFG::qVector3::msZero.y;
          *(v22 - 2) = UFG::qVector3::msZero.x;
          v30 = UFG::qVector3::msZero.z;
        }
        *v22 = v30;
        *(v22 - 1) = v29;
        v22 += 3;
        v21 += 88i64;
        --v23;
      }
      while ( v23 );
    }
    center = UFG::qVector3::msZero;
    UFG::Editor::Utility::FindMinimalBoundingSphere(&center, &radius, &points, v20);
    v31 = UFG::qMatrix44::msIdentity.v1;
    v32 = UFG::qMatrix44::msIdentity.v2;
    v33 = UFG::qMatrix44::msIdentity.v3;
    v4->v0 = UFG::qMatrix44::msIdentity.v0;
    v34 = center.x;
    v4->v1 = v31;
    v31.x = center.y;
    v4->v2 = v32;
    v4->v3 = v33;
    v4->v3.x = v34;
    v4->v3.w = 1.0;
    v35 = center.z;
    v4->v3.y = v31.x;
    v4->v3.z = v35;
  }
  return v4;
}

