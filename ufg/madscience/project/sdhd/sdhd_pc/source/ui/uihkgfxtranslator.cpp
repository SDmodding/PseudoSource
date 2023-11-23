// File Line: 146
// RVA: 0x5EE7F0
char __fastcall IsRemappable(unsigned int hash)
{
  int v1; // edx
  const unsigned int *i; // rax

  v1 = 0;
  for ( i = NonRemappable; hash != *i; ++i )
  {
    if ( (unsigned int)++v1 >= 0x28 )
      return 1;
  }
  return 0;
}

// File Line: 161
// RVA: 0x5EEA60
char __fastcall UIHKDictionary::KeyTextureReplaced(unsigned int hash, UFG::qString *keyStr)
{
  int v4; // r15d
  __int64 v5; // r8
  const unsigned int *v6; // rax
  int v7; // r15d
  const char *v8; // rax
  char Key; // al
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  unsigned int v12; // ecx
  const unsigned int *v13; // rax
  unsigned int *v14; // rsi
  const char **v15; // rbx
  __int64 v16; // r12
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  const char *v19; // rax
  char v20; // al
  UFG::qString *v21; // rax
  UFG::qString *v22; // rax
  UFG::UI::eButtons i; // ebx
  char v24; // al
  char *GamepadButtonTextureName; // rax
  char v26; // al
  UFG::UI::eButtons v27; // ecx
  unsigned int v28; // eax
  char *KeyboardButtonTextureNameNonRemappable; // rdx
  char v30; // al
  const char **v32; // rbx
  __int64 v33; // rdi
  UFG::qString rhs; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qString v35; // [rsp+58h] [rbp-80h] BYREF
  const char *v36; // [rsp+80h] [rbp-58h]
  const char *v37; // [rsp+88h] [rbp-50h]
  const char *v38; // [rsp+90h] [rbp-48h]
  const char *v39; // [rsp+98h] [rbp-40h]
  char *v40; // [rsp+A0h] [rbp-38h]
  const char *v41; // [rsp+A8h] [rbp-30h]
  char *v42; // [rsp+B0h] [rbp-28h]
  char *v43; // [rsp+B8h] [rbp-20h]
  const char *v44; // [rsp+C0h] [rbp-18h]
  const char *v45; // [rsp+C8h] [rbp-10h]
  const char *v46; // [rsp+D0h] [rbp-8h]
  const char *v47; // [rsp+D8h] [rbp+0h]
  const char *v48; // [rsp+E0h] [rbp+8h]
  const char *v49; // [rsp+E8h] [rbp+10h]
  UFG::qString attribute; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v51; // [rsp+120h] [rbp+48h]
  UFG::qString v52; // [rsp+128h] [rbp+50h] BYREF
  UFG::qString result; // [rsp+150h] [rbp+78h] BYREF
  UFG::qString v54; // [rsp+178h] [rbp+A0h] BYREF
  UFG::qString v55; // [rsp+1A0h] [rbp+C8h] BYREF

  v51 = -2i64;
  UFG::qString::ReplaceString(keyStr, "\"", "", 0);
  v4 = 0;
  v5 = 0i64;
  v6 = MeleeHints;
  while ( hash != *v6 )
  {
    v5 = (unsigned int)(v5 + 1);
    ++v6;
    if ( (unsigned int)v5 >= 5 )
      goto LABEL_8;
  }
  UFG::qString::qString(&v35, "BUTTON_MOUSE_M", v5);
  v7 = UFG::qString::ReplaceString(keyStr, "BUTTON_R_STICK", v35.mData, 0);
  v8 = &customCaption;
  if ( REMAP_ID_MELEE_ATTACK_2 != REMAP_ID_INVALID_2 )
  {
    Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_MELEE_ATTACK_2);
    v8 = UFG::KeyToTextureName(Key);
  }
  UFG::qString::qString(&rhs, v8);
  v10 = UFG::operator+(&result, "", &rhs);
  v11 = UFG::operator+(&v52, v10, "");
  UFG::qString::Set(&rhs, v11->mData, v11->mLength, 0i64, 0);
  UFG::qString::~qString(&v52);
  UFG::qString::~qString(&result);
  v4 = UFG::qString::ReplaceString(keyStr, "BUTTON_R2", rhs.mData, 0) + v7;
  UFG::qString::~qString(&rhs);
  UFG::qString::~qString(&v35);
LABEL_8:
  v12 = 0;
  v13 = DrivingHints;
  while ( hash != *v13 )
  {
    ++v12;
    ++v13;
    if ( v12 >= 0x1B )
      goto LABEL_18;
  }
  v35.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_R2";
  v35.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_L2";
  *(_QWORD *)&v35.mMagic = &customCaption;
  v35.mData = &customCaption;
  *(_QWORD *)&v35.mStringHash32 = "BUTTON_BACK";
  v36 = "BUTTON_R1";
  v37 = "BUTTON_L1";
  v38 = "BUTTON_BUTTON1";
  v39 = "BUTTON_R3";
  v40 = &customCaption;
  v41 = "BUTTON_ACCEPT";
  v42 = &customCaption;
  v43 = &customCaption;
  v14 = (unsigned int *)DrivingRemapIds_0;
  v15 = (const char **)&v35;
  v16 = 13i64;
  do
  {
    UFG::qString::qString(&rhs, *v15);
    if ( rhs.mLength )
    {
      v17 = UFG::operator+(&v52, "", &rhs);
      v18 = UFG::operator+(&result, v17, "");
      UFG::qString::Set(&rhs, v18->mData, v18->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v52);
      v19 = &customCaption;
      if ( *v14 != REMAP_ID_INVALID_2 )
      {
        v20 = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v14);
        v19 = UFG::KeyToTextureName(v20);
      }
      UFG::qString::qString(&v35, v19);
      v21 = UFG::operator+(&v54, "", &v35);
      v22 = UFG::operator+(&v55, v21, "");
      UFG::qString::Set(&v35, v22->mData, v22->mLength, 0i64, 0);
      UFG::qString::~qString(&v55);
      UFG::qString::~qString(&v54);
      v4 += UFG::qString::ReplaceString(keyStr, rhs.mData, v35.mData, 0);
      UFG::qString::~qString(&v35);
    }
    UFG::qString::~qString(&rhs);
    ++v15;
    ++v14;
    --v16;
  }
  while ( v16 );
LABEL_18:
  for ( i = ACCEPT_BUTTON; (unsigned int)i < ACCEPT_BUTTON_HOLD; ++i )
  {
    v24 = IsRemappable(hash);
    GamepadButtonTextureName = UFG::UI::GetGamepadButtonTextureName(i, v24);
    UFG::qString::qString(&rhs, GamepadButtonTextureName);
    v26 = IsRemappable(hash);
    v27 = i;
    if ( !v26 )
      goto LABEL_24;
    v28 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(i, RemapContext_OnFoot);
    KeyboardButtonTextureNameNonRemappable = &customCaption;
    if ( v28 != REMAP_ID_INVALID_2 )
    {
      v30 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v28);
      KeyboardButtonTextureNameNonRemappable = (char *)UFG::KeyToTextureName(v30);
    }
    if ( !*KeyboardButtonTextureNameNonRemappable )
    {
      v27 = i;
LABEL_24:
      KeyboardButtonTextureNameNonRemappable = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v27);
    }
    UFG::qString::qString(&v35, KeyboardButtonTextureNameNonRemappable);
    v4 += UFG::qString::ReplaceString(keyStr, rhs.mData, v35.mData, 0);
    UFG::qString::~qString(&v35);
    UFG::qString::~qString(&rhs);
  }
  if ( !v4 )
    return 0;
  v35.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_ARROW_LR";
  v35.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"BUTTON_ARROW_UD";
  *(_QWORD *)&v35.mMagic = "BUTTON_BACKSLASH";
  v35.mData = "BUTTON_BACKSPACE";
  *(_QWORD *)&v35.mStringHash32 = "BUTTON_CAPSLOCK";
  v36 = "BUTTON_CTRL";
  v37 = "BUTTON_LCTRL";
  v38 = "BUTTON_RCTRL";
  v39 = "BUTTON_ENTER";
  v40 = "BUTTON_NUMZERO";
  v41 = "BUTTON_SHIFT";
  v42 = "BUTTON_LSHIFT";
  v43 = "BUTTON_RSHIFT";
  v44 = "BUTTON_SPACE";
  v45 = "BUTTON_TAB";
  v46 = "BUTTON_MOUSE4";
  v47 = "BUTTON_MOUSE5";
  v48 = "BUTTON_LALT";
  v49 = "BUTTON_RALT";
  UFG::qString::qString(&attribute, "width=");
  v32 = (const char **)&v35;
  v33 = 19i64;
  do
  {
    UIHKDictionary::AdjustAttribute(keyStr, *v32++, &attribute, 2.0);
    --v33;
  }
  while ( v33 );
  UFG::qString::Set(&attribute, "vspace=");
  UIHKDictionary::AdjustAttribute(keyStr, attribute.mData, &attribute, 0.5);
  UFG::qString::~qString(&attribute);
  return 1;
}

// File Line: 251
// RVA: 0x5D31B0
void __fastcall UIHKDictionary::AdjustAttribute(
        UFG::qString *strKey,
        const char *marker,
        UFG::qString *attribute,
        float adjustment)
{
  UFG::qString *v7; // rax
  char *mData; // rsi
  int mLength; // r12d
  int i; // edi
  unsigned int v11; // r14d
  unsigned int v12; // esi
  unsigned int v13; // r15d
  int v14; // esi
  int v15; // eax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  int v19; // eax
  UFG::qString rhs; // [rsp+30h] [rbp-98h] BYREF
  UFG::qString result; // [rsp+58h] [rbp-70h] BYREF
  char *nptr; // [rsp+90h] [rbp-38h]
  UFG::qString lhs; // [rsp+A0h] [rbp-28h] BYREF
  UFG::qString v24; // [rsp+C8h] [rbp+0h] BYREF
  UFG::qString v25; // [rsp+F0h] [rbp+28h] BYREF
  UFG::qString v26; // [rsp+118h] [rbp+50h] BYREF
  UFG::qString v27; // [rsp+140h] [rbp+78h] BYREF
  char *str; // [rsp+1C0h] [rbp+F8h]
  char *v29; // [rsp+1C8h] [rbp+100h]

  rhs.mData = (char *)-2i64;
  v7 = UFG::qString::ToUpper(attribute, &result);
  UFG::qString::ReplaceString(strKey, v7->mData, attribute->mData, 0);
  UFG::qString::~qString(&result);
  mData = attribute->mData;
  v29 = mData;
  mLength = attribute->mLength;
  for ( i = UFG::qString::find(strKey, marker); i != UFG::qString::npos; mData = v29 )
  {
    UFG::qString::Substring(strKey, &rhs, i, -1);
    v11 = UFG::qString::find(&rhs, mData);
    UFG::qString::Substring(&rhs, &result, v11 + mLength, -1);
    v12 = UFG::qString::find(&result, "");
    if ( v12 != UFG::qString::npos )
      v12 += v11 + mLength;
    v13 = UFG::qString::find(&rhs, ">");
    if ( v12 == UFG::qString::npos || v11 >= v12 || v13 == UFG::qString::npos || v11 >= v13 )
    {
      i = UFG::qString::npos;
    }
    else
    {
      v14 = v12 - v11 - mLength;
      UFG::qString::Substring(strKey, &lhs, 0, mLength + v11 + i);
      UFG::qString::Substring(strKey, (UFG::qString *)&rhs.mStringHash32, mLength + i + v14 + v11, -1);
      UFG::qString::Substring(strKey, (UFG::qString *)&result.mStringHash32, mLength + v11 + i, v14);
      v15 = atol(nptr);
      v16 = UFG::qString::FormatEx(&v27, "%d", (unsigned int)(int)(float)((float)v15 * adjustment));
      v17 = UFG::operator+(&v26, &lhs, v16);
      v18 = UFG::operator+(&v25, v17, (UFG::qString *)&rhs.mStringHash32);
      UFG::qString::Set(strKey, v18->mData, v18->mLength, 0i64, 0);
      UFG::qString::~qString(&v25);
      UFG::qString::~qString(&v26);
      UFG::qString::~qString(&v27);
      UFG::qString::Substring(strKey, &v24, v13 + i, -1);
      v19 = UFG::qString::find(&v24, str);
      if ( v19 == UFG::qString::npos )
        i = UFG::qString::npos;
      else
        i += v13 + v19;
      UFG::qString::~qString(&v24);
      UFG::qString::~qString((UFG::qString *)&result.mStringHash32);
      UFG::qString::~qString((UFG::qString *)&rhs.mStringHash32);
      UFG::qString::~qString(&lhs);
    }
    UFG::qString::~qString(&result);
    UFG::qString::~qString(&rhs);
  }
}

// File Line: 302
// RVA: 0x5C3F00
void __fastcall UIHKGFxTranslator::UIHKGFxTranslator(UIHKGFxTranslator *this)
{
  UFG::qString *mTranslatedStrings; // rbx
  __int64 v3; // rdi

  UFG::UIGfxTranslator::UIGfxTranslator(this);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UIHKGFxTranslator::`vftable;
  mTranslatedStrings = this->mTranslatedStrings;
  v3 = 512i64;
  `eh vector constructor iterator(
    this->mTranslatedStrings,
    0x28ui64,
    512,
    (void (__fastcall *)(void *))UFG::qString::qString);
  this->mCurrentStringIndex = 0;
  do
  {
    UFG::qString::Set(mTranslatedStrings++, &customCaption);
    --v3;
  }
  while ( v3 );
}

// File Line: 316
// RVA: 0x612DE0
void __fastcall UIHKGFxTranslator::Translate(
        UIHKGFxTranslator *this,
        Scaleform::GFx::Translator::TranslateInfo *ptranslateInfo)
{
  const wchar_t *pKey; // rsi
  int v5; // eax
  int v6; // edi
  char *v7; // rax
  char *v8; // rbp
  int v9; // edi
  unsigned int v10; // edi
  char *v11; // rax
  char *mData; // rsi
  bool v13; // di
  void *v14; // rcx
  unsigned int v15; // r14d
  UFG::allocator::free_link *v16; // rax
  wchar_t *v17; // rdi
  UFG::qString keyStr; // [rsp+28h] [rbp-40h] BYREF

  if ( ptranslateInfo )
  {
    pKey = ptranslateInfo->pKey;
    v5 = UFG::qStringLength(ptranslateInfo->pKey);
    v6 = v5;
    if ( v5 )
    {
      if ( this->mLanguage )
      {
        if ( *pKey == 36 && v5 != 1 )
          goto LABEL_13;
      }
      else
      {
        if ( !gUIShowIconsInBlankLoc || (unsigned __int16)(*pKey - 48) > 9u && *pKey != 45 )
        {
LABEL_13:
          v7 = (char *)UFG::qMalloc(v5, &customCaption, 0i64);
          v8 = v7;
          if ( !v7 )
            return;
          v9 = v6 - 1;
          UFG::qWideStringCopy(v7, pKey + 1);
          if ( v8[v9 - 1] == 13 )
            v8[v9 - 1] = 0;
          UFG::qString::qString(&keyStr);
          v10 = UFG::qStringHashUpper32(v8, -1);
          v11 = UFG::UIGfxTranslator::Translate(this, v10);
          UFG::qString::Set(&keyStr, v11);
          if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
            UIHKDictionary::KeyTextureReplaced(v10, &keyStr);
          mData = keyStr.mData;
          v13 = keyStr.mData != 0i64;
          if ( this->mLanguage
            || gUIShowIconsInBlankLoc
            && keyStr.mData
            && !(unsigned int)UFG::qStringCompareInsensitive(keyStr.mData, "<img", 4) )
          {
            if ( v13 )
            {
              v15 = UFG::qStringLength(mData);
              v16 = UFG::qMalloc(2 * v15 + 2, &customCaption, 0i64);
              v17 = (wchar_t *)v16;
              if ( v16 )
              {
                UFG::qMemSet(v16, 0, 2 * v15 + 2);
                Scaleform::UTF8Util::DecodeString(v17, mData, v15);
                if ( (ptranslateInfo->Flags & 4) != 0 )
                {
                  Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, v17, v15);
                  ptranslateInfo->Flags |= 2u;
                }
                else
                {
                  Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, v17, v15);
                }
                operator delete[](v8);
                v14 = v17;
                goto LABEL_30;
              }
            }
          }
          else
          {
            Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, &customCaption, 0i64);
          }
          v14 = v8;
LABEL_30:
          operator delete[](v14);
          UFG::qString::~qString(&keyStr);
          return;
        }
        if ( (ptranslateInfo->Flags & 4) != 0 )
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, pKey, v5);
          ptranslateInfo->Flags |= 2u;
        }
        else
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, pKey, v5);
        }
      }
    }
  }
}

// File Line: 419
// RVA: 0x612D30
char *__fastcall UIHKGFxTranslator::Translate(UIHKGFxTranslator *this, unsigned int hash)
{
  char *result; // rax
  const char *v5; // rdx
  int v6; // eax

  result = UFG::UIGfxTranslator::Translate(this, hash);
  v5 = result;
  if ( result )
  {
    v6 = ++this->mCurrentStringIndex;
    if ( v6 >= 512 )
      v6 = 0;
    this->mCurrentStringIndex = v6;
    UFG::qString::Set((UFG::qString *)((char *)this->mTranslatedStrings + 32 * v6 + 8 * v6), v5);
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      UIHKDictionary::KeyTextureReplaced(
        hash,
        (UFG::qString *)((char *)this->mTranslatedStrings
                       + 32 * this->mCurrentStringIndex
                       + 8 * this->mCurrentStringIndex));
    return this->mTranslatedStrings[this->mCurrentStringIndex].mData;
  }
  return result;
}

