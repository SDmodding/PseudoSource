// File Line: 46
// RVA: 0x838350
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledSet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::Value *result, bool value)
{
  this->pTraits.pObject->pVM[1].CallStack.gap0[0] = value;
}

// File Line: 56
// RVA: 0x838310
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::enabledGet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, bool *result)
{
  *result = this->pTraits.pObject->pVM[1].CallStack.gap0[0];
}

// File Line: 65
// RVA: 0x855480
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceSet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::Value *result, bool value)
{
  Scaleform::GFx::AS3::VM *v3; // rax
  void *(__fastcall *v4)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  v3 = this->pTraits.pObject->pVM;
  if ( v3[1].CallStack.gap0[0] )
  {
    v4 = v3[1].vfptr[2].__vecDelDtor;
    if ( value )
      *((_DWORD *)v4 + 5300) |= 0x800u;
    else
      *((_DWORD *)v4 + 5300) &= 0xFFFFF7FF;
  }
}

// File Line: 79
// RVA: 0x855450
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceGet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, bool *result)
{
  Scaleform::GFx::AS3::VM *v2; // rax

  v2 = this->pTraits.pObject->pVM;
  if ( v2[1].CallStack.gap0[0] )
    *result = (*((_DWORD *)v2[1].vfptr[2].__vecDelDtor + 5300) >> 11) & 1;
}

// File Line: 92
// RVA: 0x84CF70
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getTopMostEntity(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result, long double x, long double y, bool testAll)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v5; // rdi
  Scaleform::GFx::MovieImpl *v6; // rsi
  Scaleform::GFx::DisplayObjectBase *v7; // rcx
  _QWORD *v8; // rbx
  float v9; // xmm4_4
  float v10; // xmm3_4
  Scaleform::GFx::InteractiveObject *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v14; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // rcx
  unsigned int v18; // eax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-48h]
  Scaleform::Render::Point<float> mousePos; // [rsp+80h] [rbp+8h]

  v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  v6 = (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  v7 = (Scaleform::GFx::DisplayObjectBase *)&v6->pMainMovie->vfptr;
  if ( !v7 )
  {
    v17 = result->pObject;
    if ( !result->pObject )
      return;
    if ( (unsigned __int8)v17 & 1 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
    }
    else
    {
      v18 = v17->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v17->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v17->vfptr);
      }
    }
    goto LABEL_20;
  }
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v7, &pmat);
  v8 = 0i64;
  v9 = x * 20.0;
  v10 = y * 20.0;
  mousePos.x = (float)((float)(pmat.M[0][1] * v10) + (float)(pmat.M[0][0] * v9)) + pmat.M[0][3];
  mousePos.y = (float)((float)(pmat.M[1][0] * v9) + (float)(pmat.M[1][1] * v10)) + pmat.M[1][3];
  v11 = Scaleform::GFx::MovieImpl::GetTopMostEntity(v6, &mousePos, 0, testAll, 0i64);
  if ( !v11 )
  {
    v15.pObject = v5->pObject;
    if ( !v5->pObject )
      return;
    if ( (_QWORD)v15.pObject & 1 )
    {
      v5->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v15.pObject - 1);
    }
    else
    {
      v16 = v15.pObject->RefCount;
      if ( v16 & 0x3FFFFF )
      {
        v15.pObject->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15.pObject->vfptr);
      }
    }
LABEL_20:
    v5->pObject = 0i64;
    return;
  }
  v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                    + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
  if ( v12 )
    v8 = (_QWORD *)(v12 - 56);
  LOBYTE(v13) = 1;
  (*(void (__fastcall **)(_QWORD *, __int64))(*v8 + 112i64))(v8, v13);
  v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[2];
  if ( !v14 )
    v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[1];
  if ( (unsigned __int8)v14 & 1 )
    v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v14 - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v5, v14);
}

// File Line: 129
// RVA: 0x84BAF0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseTopMostEntity(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result, bool testAll, unsigned int mouseIndex)
{
  __int64 v4; // rsi
  bool v5; // bp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v6; // rdi
  void *(__fastcall *v7)(Scaleform::GFx::AS3::VM *, unsigned int); // r14
  _QWORD *v8; // rbx
  signed __int64 v9; // rax
  float v10; // xmm1_4
  Scaleform::GFx::InteractiveObject *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v14; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v15; // rcx
  unsigned int v16; // eax
  Scaleform::Render::Point<float> mousePos; // [rsp+50h] [rbp+8h]

  v4 = mouseIndex;
  v5 = testAll;
  v6 = result;
  v7 = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  if ( mouseIndex < (*(unsigned int (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int)))(*(_QWORD *)v7 + 352i64))(v7) )
  {
    v8 = 0i64;
    if ( (unsigned int)v4 < 6 )
      v9 = (signed __int64)v7 + 80 * v4 + 8696;
    else
      v9 = 0i64;
    v10 = *(float *)(v9 + 60);
    mousePos.x = *(float *)(v9 + 56);
    mousePos.y = v10;
    v11 = Scaleform::GFx::MovieImpl::GetTopMostEntity((Scaleform::GFx::MovieImpl *)v7, &mousePos, v4, v5, 0i64);
    if ( v11 )
    {
      v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                        + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
      if ( v12 )
        v8 = (_QWORD *)(v12 - 56);
      LOBYTE(v13) = 1;
      (*(void (__fastcall **)(_QWORD *, __int64))(*v8 + 112i64))(v8, v13);
      v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[2];
      if ( !v14 )
        v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8[1];
      if ( (unsigned __int8)v14 & 1 )
        v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v14 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6,
        v14);
    }
    else
    {
      v15.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6->pObject;
      if ( v6->pObject )
      {
        if ( (_QWORD)v15.pObject & 1 )
        {
          v6->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)&v15.pObject[-1].List.Data.Policy.Capacity
                                                                                    + 7);
        }
        else
        {
          v16 = v15.pObject->RefCount;
          if ( v16 & 0x3FFFFF )
          {
            v15.pObject->RefCount = v16 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15.pObject->vfptr);
          }
        }
        v6->pObject = 0i64;
      }
    }
  }
}

// File Line: 153
// RVA: 0x85B990
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setMouseCursorType(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *cursor, unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr,
    cursor,
    mouseIndex);
}

// File Line: 161
// RVA: 0x84BAA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseCursorType(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::ASString *result, unsigned int mouseIndex)
{
  Scaleform::GFx::AS3::MovieRoot *v3; // rcx

  v3 = (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr;
  if ( mouseIndex < 6 )
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
      v3,
      result,
      v3->pMovieImpl->mMouseState[mouseIndex].mPresetCursorType);
  else
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(v3, result, MEMORY[0x40]);
}

// File Line: 169
// RVA: 0x84B650
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getEdgeAAMode(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, unsigned int *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v3; // rdi
  unsigned int *v4; // rbx
  unsigned __int64 v5; // rax
  int v6; // eax
  unsigned int v7; // eax

  v3 = this;
  v4 = result;
  v5 = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&dispObj->pDispObj.pObject->vfptr);
  v6 = *(_WORD *)(*(_QWORD *)(*(_QWORD *)((v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8
                            * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v5
                                                                                                  - (v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                                                  - 56)
                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                             + ((unsigned __int64)((unsigned __int128)((signed __int64)(v5
                                                                                      - (v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                                      - 56)
                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                            + 40)
                + 10i64) & 0xC;
  if ( v6 == 4 )
  {
    *v4 = v3->EDGEAA_ON;
  }
  else if ( v6 == 8 )
  {
    *v4 = v3->EDGEAA_OFF;
  }
  else
  {
    if ( v6 == 12 )
      v7 = v3->EDGEAA_DISABLE;
    else
      v7 = v3->EDGEAA_INHERIT;
    *v4 = v7;
  }
}

// File Line: 185
// RVA: 0x85B250
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setEdgeAAMode(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj, unsigned int mode)
{
  Scaleform::Render::EdgeAAMode v4; // ebx
  Scaleform::Render::TreeNode *v5; // rax

  v4 = 0;
  if ( mode == this->EDGEAA_DISABLE )
  {
    v4 = 12;
  }
  else if ( mode == this->EDGEAA_ON )
  {
    v4 = 4;
  }
  else if ( mode == this->EDGEAA_OFF )
  {
    v4 = 8;
  }
  v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&dispObj->pDispObj.pObject->vfptr);
  Scaleform::Render::TreeNode::SetEdgeAAMode(v5, v4);
}

// File Line: 204
// RVA: 0x855660
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::numControllersGet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, unsigned int *result)
{
  Scaleform::GFx::AS3::VM *v2; // rax

  v2 = this->pTraits.pObject->pVM;
  if ( v2[1].CallStack.gap0[0] )
    *result = (*(__int64 (**)(void))(*(_QWORD *)v2[1].vfptr[2].__vecDelDtor + 368i64))();
}

// File Line: 217
// RVA: 0x86BC90
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::visibleRectGet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rdi
  Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *v3; // rbx
  void *(__fastcall *v4)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  long double v5; // rcx
  char v6; // ST20_1
  bool v7; // zf
  float v8; // [rsp+28h] [rbp-69h]
  float v9; // [rsp+2Ch] [rbp-65h]
  float v10; // [rsp+30h] [rbp-61h]
  float v11; // [rsp+34h] [rbp-5Dh]
  Scaleform::GFx::AS3::Value v12; // [rsp+38h] [rbp-59h]
  __int64 v13; // [rsp+58h] [rbp-39h]
  int ptr; // [rsp+68h] [rbp-29h]
  __int64 v15; // [rsp+70h] [rbp-21h]
  double v16; // [rsp+78h] [rbp-19h]
  int v17; // [rsp+88h] [rbp-9h]
  __int64 v18; // [rsp+90h] [rbp-1h]
  double v19; // [rsp+98h] [rbp+7h]
  int v20; // [rsp+A8h] [rbp+17h]
  __int64 v21; // [rsp+B0h] [rbp+1Fh]
  double v22; // [rsp+B8h] [rbp+27h]
  int v23; // [rsp+C8h] [rbp+37h]
  __int64 v24; // [rsp+D0h] [rbp+3Fh]
  double v25; // [rsp+D8h] [rbp+47h]

  v13 = -2i64;
  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  (*(void (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), float *))(*(_QWORD *)v4 + 144i64))(
    v4,
    &v8);
  ptr = 4;
  v15 = 0i64;
  v16 = v8;
  v17 = 4;
  v18 = 0i64;
  v19 = v9;
  v20 = 4;
  v21 = 0i64;
  v22 = (float)(v10 - v8);
  v23 = 4;
  v24 = 0i64;
  v25 = (float)(v11 - v9);
  v12.Flags = 0;
  v12.Bonus.pWeakProxy = 0i64;
  v5 = v3->pTraits.pObject->pVM[1].ExceptionObj.value.VNumber;
  v6 = 1;
  (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Value *, signed __int64, int *, char))(**(_QWORD **)&v5
                                                                                                 + 96i64))(
    COERCE_LONG_DOUBLE(*(_QWORD *)&v5),
    &v12,
    4i64,
    &ptr,
    v6);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    v2,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v12.value.VS._1.VStr);
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags >> 9) & 1 )
    {
      v7 = v12.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v12.Bonus.pWeakProxy = 0i64;
      v12.value = 0ui64;
      v12.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 234
// RVA: 0x850AE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::isScaleformGet(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this, bool *result)
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
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double,double,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getTopMostEntity;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,bool,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseTopMostEntity;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,11,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::visibleRectGet;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::Extensions::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::ExtensionsCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::Extensions::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::ExtensionsCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::`vftable;
    LODWORD(v10[1].vfptr) = 0;
    HIDWORD(v10[1].vfptr) = 1;
    LODWORD(v10[1]._pRCC) = 2;
    HIDWORD(v10[1].pRCCRaw) = 3;
  }
  return v3;
}

