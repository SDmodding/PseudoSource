// File Line: 46
// RVA: 0x838350
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::Value *result,
        bool value)
{
  this->pTraits.pObject->pVM[1].CallStack.gap0[0] = value;
}

// File Line: 56
// RVA: 0x838310
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  *result = this->pTraits.pObject->pVM[1].CallStack.gap0[0];
}

// File Line: 65
// RVA: 0x855480
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    vecDelDtor = pVM[1].vfptr[2].__vecDelDtor;
    if ( value )
      *((_DWORD *)vecDelDtor + 5300) |= 0x800u;
    else
      *((_DWORD *)vecDelDtor + 5300) &= ~0x800u;
  }
}

// File Line: 79
// RVA: 0x855450
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
    *result = (*((_DWORD *)pVM[1].vfptr[2].__vecDelDtor + 5300) & 0x800) != 0;
}

// File Line: 92
// RVA: 0x84CF70
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getTopMostEntity(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        long double x,
        long double y,
        bool testAll)
{
  Scaleform::GFx::MovieImpl *vecDelDtor; // rsi
  Scaleform::GFx::DisplayObjectBase *pMainMovie; // rcx
  _QWORD *v8; // rbx
  float v9; // xmm4_4
  float v10; // xmm3_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  char *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::Render::Point<float> mousePos; // [rsp+80h] [rbp+8h] BYREF

  vecDelDtor = (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  pMainMovie = vecDelDtor->pMainMovie;
  if ( !pMainMovie )
  {
    pObject = result->pObject;
    if ( !result->pObject )
      return;
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    goto LABEL_20;
  }
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
  v8 = 0i64;
  v9 = x * 20.0;
  v10 = y * 20.0;
  mousePos.x = (float)((float)(pmat.M[0][1] * v10) + (float)(pmat.M[0][0] * v9)) + pmat.M[0][3];
  mousePos.y = (float)((float)(pmat.M[1][0] * v9) + (float)(pmat.M[1][1] * v10)) + pmat.M[1][3];
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(vecDelDtor, &mousePos, 0, testAll, 0i64);
  if ( !TopMostEntity )
  {
    v16 = result->pObject;
    if ( !result->pObject )
      return;
    if ( ((unsigned __int8)v16 & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v16 - 1);
    }
    else
    {
      v17 = v16->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        v16->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
LABEL_20:
    result->pObject = 0i64;
    return;
  }
  v12 = (char *)TopMostEntity + 4 * (unsigned __int8)TopMostEntity->AvmObjOffset;
  v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
  if ( v13 )
    v8 = (_QWORD *)(v13 - 56);
  LOBYTE(v14) = 1;
  (*(void (__fastcall **)(_QWORD *, __int64))(*v8 + 112i64))(v8, v14);
  v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[2];
  if ( !v15 )
    v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[1];
  if ( ((unsigned __int8)v15 & 1) != 0 )
    v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v15 - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v15);
}

// File Line: 129
// RVA: 0x84BAF0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseTopMostEntity(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        bool testAll,
        unsigned int mouseIndex)
{
  __int64 v4; // rsi
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // r14
  _QWORD *v8; // rbx
  float *v9; // rax
  float v10; // xmm1_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  char *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Render::Point<float> mousePos; // [rsp+50h] [rbp+8h] BYREF

  v4 = mouseIndex;
  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  if ( mouseIndex < (*(unsigned int (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int)))(*(_QWORD *)vecDelDtor + 352i64))(vecDelDtor) )
  {
    v8 = 0i64;
    if ( (unsigned int)v4 < 6 )
      v9 = (float *)((char *)vecDelDtor + 80 * v4 + 8696);
    else
      v9 = 0i64;
    v10 = v9[15];
    mousePos.x = v9[14];
    mousePos.y = v10;
    TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(
                      (Scaleform::GFx::MovieImpl *)vecDelDtor,
                      &mousePos,
                      v4,
                      testAll,
                      0i64);
    if ( TopMostEntity )
    {
      v12 = (char *)TopMostEntity + 4 * (unsigned __int8)TopMostEntity->AvmObjOffset;
      v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
      if ( v13 )
        v8 = (_QWORD *)(v13 - 56);
      LOBYTE(v14) = 1;
      (*(void (__fastcall **)(_QWORD *, __int64))(*v8 + 112i64))(v8, v14);
      v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[2];
      if ( !v15 )
        v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[1];
      if ( ((unsigned __int8)v15 & 1) != 0 )
        v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v15 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v15);
    }
    else
    {
      pObject = result->pObject;
      if ( result->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
        result->pObject = 0i64;
      }
    }
  }
}

// File Line: 153
// RVA: 0x85B990
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setMouseCursorType(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *cursor,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr,
    cursor,
    mouseIndex);
}

// File Line: 161
// RVA: 0x84BAA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseCursorType(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::ASString *result,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot *vfptr; // rcx

  vfptr = (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr;
  if ( mouseIndex < 6 )
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
      vfptr,
      result,
      vfptr->pMovieImpl->mMouseState[mouseIndex].mPresetCursorType);
  else
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(vfptr, result, MEMORY[0x40]);
}

// File Line: 169
// RVA: 0x84B650
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getEdgeAAMode(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj)
{
  unsigned __int64 RenderNode; // rax
  int v6; // eax
  unsigned int EDGEAA_DISABLE; // eax

  RenderNode = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode(dispObj->pDispObj.pObject);
  v6 = *(_WORD *)(*(_QWORD *)(*(_QWORD *)((RenderNode & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8i64 * (unsigned int)((int)(RenderNode - (RenderNode & 0xFFFFF000) - 56) / 56)
                            + 40)
                + 10i64) & 0xC;
  if ( v6 == 4 )
  {
    *result = this->EDGEAA_ON;
  }
  else if ( v6 == 8 )
  {
    *result = this->EDGEAA_OFF;
  }
  else
  {
    if ( v6 == 12 )
      EDGEAA_DISABLE = this->EDGEAA_DISABLE;
    else
      EDGEAA_DISABLE = this->EDGEAA_INHERIT;
    *result = EDGEAA_DISABLE;
  }
}

// File Line: 185
// RVA: 0x85B250
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setEdgeAAMode(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj,
        unsigned int mode)
{
  Scaleform::Render::EdgeAAMode v4; // ebx
  Scaleform::Render::TreeNode *RenderNode; // rax

  v4 = EdgeAA_Inherit;
  if ( mode == this->EDGEAA_DISABLE )
  {
    v4 = EdgeAA_Disable;
  }
  else if ( mode == this->EDGEAA_ON )
  {
    v4 = EdgeAA_On;
  }
  else if ( mode == this->EDGEAA_OFF )
  {
    v4 = EdgeAA_Off;
  }
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(dispObj->pDispObj.pObject);
  Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, v4);
}

// File Line: 204
// RVA: 0x855660
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::numControllersGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
    *result = (*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int)))(*(_QWORD *)pVM[1].vfptr[2].__vecDelDtor + 368i64))(pVM[1].vfptr[2].__vecDelDtor);
}

// File Line: 217
// RVA: 0x86BC90
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::visibleRectGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  Scaleform::GFx::AS3::Value::V1U v5; // rcx
  float v7; // [rsp+30h] [rbp-69h] BYREF
  float v8; // [rsp+34h] [rbp-65h]
  Scaleform::GFx::AS3::Value v9; // [rsp+38h] [rbp-61h] BYREF
  __int64 v10; // [rsp+58h] [rbp-41h]
  __int64 v11; // [rsp+60h] [rbp-39h]
  __int64 v12[4]; // [rsp+70h] [rbp-29h] BYREF
  __int64 v13; // [rsp+90h] [rbp-9h]
  __int64 v14; // [rsp+98h] [rbp-1h]
  double v15; // [rsp+A0h] [rbp+7h]
  __int64 v16; // [rsp+B0h] [rbp+17h]
  __int64 v17; // [rsp+B8h] [rbp+1Fh]
  double v18; // [rsp+C0h] [rbp+27h]
  __int64 v19; // [rsp+D0h] [rbp+37h]
  __int64 v20; // [rsp+D8h] [rbp+3Fh]
  double v21; // [rsp+E0h] [rbp+47h]

  v11 = -2i64;
  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), float *))(*(_QWORD *)vecDelDtor
                                                                                                 + 144i64))(
    vecDelDtor,
    &v7);
  LODWORD(v12[0]) = 4;
  v12[1] = 0i64;
  *(double *)&v12[2] = v7;
  LODWORD(v13) = 4;
  v14 = 0i64;
  v15 = v8;
  LODWORD(v16) = 4;
  v17 = 0i64;
  v18 = (float)(*(float *)&v9.Flags - v7);
  LODWORD(v19) = 4;
  v20 = 0i64;
  v21 = (float)(*((float *)&v9.Flags + 1) - v8);
  LODWORD(v9.Bonus.pWeakProxy) = 0;
  v9.value.VS._1.VStr = 0i64;
  v5 = this->pTraits.pObject->pVM[1].ExceptionObj.value.VS._1;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value::Extra *, __int64, __int64 *, char))v5.VStr->pData
   + 12))(
    v5,
    &v9.Bonus,
    4i64,
    v12,
    1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v9.value.VS._2.VObj);
  if ( (unsigned __int64)((__int64)v9.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)v9.Bonus.pWeakProxy & 0x200) != 0 )
    {
      if ( LODWORD(v9.value.VS._1.VStr->pData)-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v9.value = 0ui64;
      v10 = 0i64;
      LODWORD(v9.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v9.Bonus);
    }
  }
  `eh vector destructor iterator(v12, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 234
// RVA: 0x850AE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::isScaleformGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  *result = 1;
}

// File Line: 258
// RVA: 0x1590760
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_0_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,0,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledSet;
  return result;
}

// File Line: 259
// RVA: 0x1589BF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,1,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledGet;
  return result;
}

// File Line: 260
// RVA: 0x15906D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_2_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,2,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceSet;
  return result;
}

// File Line: 261
// RVA: 0x1589C20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_3_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA00 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,3,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceGet;
  return result;
}

// File Line: 262
// RVA: 0x15963A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject__double_double_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA10 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double,double,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *, long double, long double, bool))Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getTopMostEntity;
  return result;
}

// File Line: 263
// RVA: 0x1594F60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject__bool_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA20 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,bool,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *, bool, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseTopMostEntity;
  return result;
}

// File Line: 264
// RVA: 0x1594F90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_6_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setMouseCursorType;
  return result;
}

// File Line: 265
// RVA: 0x1590700
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_7_Scaleform::GFx::ASString_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA40 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,7,Scaleform::GFx::ASString,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseCursorType;
  return result;
}

// File Line: 266
// RVA: 0x1590730
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_8_unsigned_long_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA50 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,8,unsigned long,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getEdgeAAMode;
  return result;
}

// File Line: 267
// RVA: 0x1594FC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_9_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA60 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setEdgeAAMode;
  return result;
}

// File Line: 268
// RVA: 0x1589C50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_10_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA70 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,10,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::numControllersGet;
  return result;
}

// File Line: 269
// RVA: 0x1589C80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_11_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA80 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,11,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *))Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::visibleRectGet;
  return result;
}

// File Line: 270
// RVA: 0x1589CB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::Extensions_12_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EA90 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,12,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::isScaleformGet;
  return result;
}

// File Line: 328
// RVA: 0x7611D0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::Extensions::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::ExtensionsCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::Extensions::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::ExtensionsCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::`vftable;
    LODWORD(v10[1].vfptr) = 0;
    HIDWORD(v10[1].vfptr) = 1;
    LODWORD(v10[1]._pRCC) = 2;
    HIDWORD(v10[1].pRCCRaw) = 3;
  }
  return result;
}

