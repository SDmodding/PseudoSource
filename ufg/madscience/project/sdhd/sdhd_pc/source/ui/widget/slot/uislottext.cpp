// File Line: 20
// RVA: 0x62FDB0
void __fastcall UFG::UISlotText::highlight(UFG::UISlotText *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::UIItem *m_item; // rdx
  UFG::UIItem *v4; // rdx
  int v5; // ecx
  UFG::UIItem *mPrev; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h] BYREF

  if ( !this->m_isHighlighted )
  {
    this->m_isHighlighted = 1;
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = 0;
    pObject = this->m_screen->mRenderable->m_movie.pObject;
    m_item = this->m_item;
    if ( m_item )
    {
      v4 = m_item + 2;
      v5 = 0;
      mPrev = (UFG::UIItem *)v4->mPrev;
      if ( mPrev != v4 )
      {
        do
        {
          ++v5;
          mPrev = (UFG::UIItem *)mPrev->mPrev;
        }
        while ( mPrev != v4 );
        if ( v5 > 0 )
        {
          pargs.Type = VT_Boolean;
          pargs.mValue.BValue = 1;
        }
      }
    }
    UFG::operator+(&result, &this->m_pathToSlot, ".highlight");
    Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, &pargs, 1u);
    UFG::qString::~qString(&result);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 46
// RVA: 0x641750
void __fastcall UFG::UISlotText::update(UFG::UISlotText *this, UFG::UIItem *item)
{
  UFG::qString *p_m_pathToSlot; // r14
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value::ValueUnion v6; // rax
  int v7; // ecx
  UFG::UIItem *mPrev; // rax
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mNext; // rcx
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-69h] BYREF
  Scaleform::GFx::Value v11; // [rsp+58h] [rbp-39h] BYREF
  Scaleform::GFx::Value v12; // [rsp+88h] [rbp-9h] BYREF
  __int64 v13; // [rsp+B8h] [rbp+27h]
  UFG::qString result; // [rsp+C0h] [rbp+2Fh] BYREF

  v13 = -2i64;
  this->m_item = item;
  p_m_pathToSlot = &this->m_pathToSlot;
  UFG::operator+((UFG::qString *)&result.mNext, &this->m_pathToSlot, ".setText");
  pObject = this->m_screen->mRenderable->m_movie.pObject;
  if ( item )
  {
    v6 = *(Scaleform::GFx::Value::ValueUnion *)&item[1].m_activationMessage;
    v11.pObjectInterface = 0i64;
    v11.Type = VT_String;
    v11.mValue = v6;
    Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, &v11, 1u);
    v7 = 0;
    mPrev = (UFG::UIItem *)item[2].mPrev;
    if ( mPrev != &item[2] )
    {
      do
      {
        ++v7;
        mPrev = (UFG::UIItem *)mPrev->mPrev;
      }
      while ( mPrev != &item[2] );
      if ( v7 > 0 )
      {
        UFG::operator+((UFG::qString *)&pargs, p_m_pathToSlot, ".setOption");
        mNext = item[2].mNext[1].mNext;
        v12.pObjectInterface = 0i64;
        v12.Type = VT_String;
        v12.mValue.pString = (const char *)mNext;
        Scaleform::GFx::Movie::Invoke(pObject, *(const char **)&pargs.Type, 0i64, &v12, 1u);
        if ( (v12.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v12.pObjectInterface->vfptr->gap8[8])(
            v12.pObjectInterface,
            &v12,
            v12.mValue);
          v12.pObjectInterface = 0i64;
        }
        v12.Type = VT_Undefined;
        UFG::qString::~qString((UFG::qString *)&pargs);
      }
    }
    if ( (v11.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v11.pObjectInterface->vfptr->gap8[8])(
        v11.pObjectInterface,
        &v11,
        v11.mValue);
      v11.pObjectInterface = 0i64;
    }
    v11.Type = VT_Undefined;
  }
  else
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = &customCaption;
    Scaleform::GFx::Movie::Invoke(pObject, result.mData, 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
  }
  UFG::qString::~qString(&result);
}

