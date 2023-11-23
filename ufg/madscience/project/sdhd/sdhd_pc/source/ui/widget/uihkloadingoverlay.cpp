// File Line: 34
// RVA: 0x6210F0
char __fastcall UFG::UIHKLoadingOverlay::handleMessage(
        UFG::UIHKLoadingOverlay *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v8[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v9; // [rsp+80h] [rbp-28h]
  int v10; // [rsp+88h] [rbp-20h]
  long double v11; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    mRenderable = screen->mRenderable;
    pObject = mRenderable->m_movie.pObject;
    if ( msgId == UI_HASH_LOADING_ICON_SHOW_9 )
    {
      Scaleform::GFx::Movie::Invoke(mRenderable->m_movie.pObject, "LoadingIcon_Show", 0i64, &customCaption);
      return 1;
    }
    if ( msgId == UI_HASH_LOADING_ICON_SHOW_NEXT_SAVE_ICON_9 )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = DOUBLE_1050_0;
      if ( (v10 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v9 + 16i64))(
          v9,
          v8,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v11));
        v9 = 0i64;
      }
      v10 = 5;
      v11 = DOUBLE_56_0;
      Scaleform::GFx::Movie::Invoke(pObject, "LoadingIcon_Show", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else if ( msgId == UI_HASH_LOADING_ICON_HIDE_9 )
    {
      Scaleform::GFx::Movie::Invoke(mRenderable->m_movie.pObject, "LoadingIcon_Hide", 0i64, &customCaption);
      return 1;
    }
  }
  return 0;
}

