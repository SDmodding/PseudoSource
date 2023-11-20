// File Line: 34
// RVA: 0x6210F0
char __fastcall UFG::UIHKLoadingOverlay::handleMessage(UFG::UIHKLoadingOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIScreenRenderable *v4; // rax
  Scaleform::GFx::Movie *v5; // rbx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v8; // [rsp+50h] [rbp-58h]
  unsigned int v9; // [rsp+58h] [rbp-50h]
  double v10; // [rsp+60h] [rbp-48h]
  char v11; // [rsp+70h] [rbp-38h]
  __int64 v12; // [rsp+80h] [rbp-28h]
  unsigned int v13; // [rsp+88h] [rbp-20h]
  long double v14; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    v4 = screen->mRenderable;
    v5 = v4->m_movie.pObject;
    if ( msgId == UI_HASH_LOADING_ICON_SHOW_9 )
    {
      Scaleform::GFx::Movie::Invoke(v4->m_movie.pObject, "LoadingIcon_Show", 0i64, &customWorldMapCaption);
      return 1;
    }
    if ( msgId == UI_HASH_LOADING_ICON_SHOW_NEXT_SAVE_ICON_9 )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v9 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(
          v8,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v10));
        v8 = 0i64;
      }
      v9 = 5;
      v10 = DOUBLE_1050_0;
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v12 + 16i64))(
          v12,
          &v11,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v14));
        v12 = 0i64;
      }
      v13 = 5;
      v14 = DOUBLE_56_0;
      Scaleform::GFx::Movie::Invoke(v5, "LoadingIcon_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else if ( msgId == UI_HASH_LOADING_ICON_HIDE_9 )
    {
      Scaleform::GFx::Movie::Invoke(v4->m_movie.pObject, "LoadingIcon_Hide", 0i64, &customWorldMapCaption);
      return 1;
    }
  }
  return 0;
}

