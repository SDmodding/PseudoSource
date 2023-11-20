// File Line: 20
// RVA: 0x62FDB0
void __fastcall UFG::UISlotText::highlight(UFG::UISlotText *this)
{
  UFG::UISlotText *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::UIItem *v3; // rdx
  signed __int64 v4; // rdx
  int v5; // ecx
  __int64 v6; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h]

  v1 = this;
  if ( !this->m_isHighlighted )
  {
    this->m_isHighlighted = 1;
    pargs.pObjectInterface = 0i64;
    pargs.Type = 2;
    pargs.mValue.BValue = 0;
    v2 = this->m_screen->mRenderable->m_movie.pObject;
    v3 = this->m_item;
    if ( v3 )
    {
      v4 = (signed __int64)&v3[2];
      v5 = 0;
      v6 = *(_QWORD *)(v4 + 8);
      if ( v6 != v4 )
      {
        do
        {
          ++v5;
          v6 = *(_QWORD *)(v6 + 8);
        }
        while ( v6 != v4 );
        if ( v5 > 0 )
        {
          pargs.Type = 2;
          pargs.mValue.BValue = 1;
        }
      }
    }
    UFG::operator+(&result, &v1->m_pathToSlot, ".highlight");
    Scaleform::GFx::Movie::Invoke(v2, result.mData, 0i64, &pargs, 1u);
    UFG::qString::~qString(&result);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 46
// RVA: 0x641750
void __fastcall UFG::UISlotText::update(UFG::UISlotText *this, UFG::UIItem *item)
{
  UFG::UIItem *v2; // rdi
  UFG::UISlotText *v3; // rbx
  UFG::qString *v4; // r14
  Scaleform::GFx::Movie *v5; // rsi
  long double v6; // rax
  int v7; // ecx
  UFG::UIItem *v8; // rax
  long double v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-69h]
  Scaleform::GFx::Value v11; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::Value v12; // [rsp+88h] [rbp-9h]
  __int64 v13; // [rsp+B8h] [rbp+27h]
  UFG::qString result; // [rsp+C0h] [rbp+2Fh]

  v13 = -2i64;
  v2 = item;
  v3 = this;
  this->m_item = item;
  v4 = &this->m_pathToSlot;
  UFG::operator+((UFG::qString *)((char *)&result + 8), &this->m_pathToSlot, ".setText");
  v5 = v3->m_screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    v6 = *(double *)&v2[1].m_activationMessage;
    v11.pObjectInterface = 0i64;
    v11.Type = 6;
    v11.mValue.NValue = v6;
    Scaleform::GFx::Movie::Invoke(v5, result.mData, 0i64, &v11, 1u);
    v7 = 0;
    v8 = (UFG::UIItem *)v2[2].mPrev;
    if ( v8 != &v2[2] )
    {
      do
      {
        ++v7;
        v8 = (UFG::UIItem *)v8->mPrev;
      }
      while ( v8 != &v2[2] );
      if ( v7 > 0 )
      {
        UFG::operator+((UFG::qString *)&pargs, v4, ".setOption");
        v9 = *(double *)&v2[2].mNext[1].mNext;
        v12.pObjectInterface = 0i64;
        v12.Type = 6;
        v12.mValue.NValue = v9;
        Scaleform::GFx::Movie::Invoke(v5, *(const char **)&pargs.Type, 0i64, &v12, 1u);
        if ( ((unsigned int)v12.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v12.pObjectInterface->vfptr->gap8[8])(
            v12.pObjectInterface,
            &v12,
            *(_QWORD *)&v12.mValue.NValue);
          v12.pObjectInterface = 0i64;
        }
        v12.Type = 0;
        UFG::qString::~qString((UFG::qString *)&pargs);
      }
    }
    if ( ((unsigned int)v11.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v11.pObjectInterface->vfptr->gap8[8])(
        v11.pObjectInterface,
        &v11,
        *(_QWORD *)&v11.mValue.NValue);
      v11.pObjectInterface = 0i64;
    }
    v11.Type = 0;
  }
  else
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = &customWorldMapCaption;
    Scaleform::GFx::Movie::Invoke(v5, result.mData, 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
  }
  UFG::qString::~qString(&result);
}

