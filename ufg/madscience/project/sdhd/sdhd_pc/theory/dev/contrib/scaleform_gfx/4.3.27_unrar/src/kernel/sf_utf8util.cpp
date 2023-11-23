// File Line: 27
// RVA: 0x9884A0
__int64 __fastcall Scaleform::UTF8Util::GetLength(char *buf, __int64 buflen)
{
  __int64 v2; // rbx
  char *v4; // r8
  __int64 result; // rax
  char v6; // dl
  char v7; // cl
  char v8; // cl
  char v9; // cl
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  v4 = buf;
  putf8Buffer = buf;
  if ( buflen != -1 )
  {
    result = 0i64;
    if ( buflen <= 0 )
      return result;
    while ( 1 )
    {
      v6 = *v4++;
      ++result;
      if ( v6 >= 0 )
        goto LABEL_30;
      if ( (v6 & 0xE0) == 0xC0 )
        goto LABEL_27;
      if ( (v6 & 0xF0) == 0xE0 )
        goto LABEL_6;
      if ( (v6 & 0xF8) == 0xF0 )
        goto LABEL_10;
      if ( (v6 & 0xFC) == 0xF8 )
        break;
      if ( (v6 & 0xFE) == 0xFC )
      {
        if ( *v4 )
        {
          if ( (*v4 & 0xC0) == 0x80 )
          {
            v7 = *++v4;
            ++result;
            if ( v7 )
            {
              if ( (v7 & 0xC0) == 0x80 )
              {
                v8 = *++v4;
                ++result;
                if ( v8 )
                {
                  if ( (v8 & 0xC0) == 0x80 )
                  {
                    v9 = *++v4;
                    ++result;
                    if ( v9 )
                    {
                      if ( (v9 & 0xC0) == 0x80 )
                      {
LABEL_26:
                        ++v4;
                        ++result;
LABEL_27:
                        if ( *v4 )
                        {
                          if ( (*v4 & 0xC0) == 0x80 )
                          {
                            ++v4;
                            ++result;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_30:
      ++v2;
      if ( result >= buflen )
        return v2;
    }
    if ( !*v4 || (*v4 & 0xC0) != 0x80 )
      goto LABEL_30;
    ++v4;
    ++result;
LABEL_10:
    if ( !*v4 || (*v4 & 0xC0) != 0x80 )
      goto LABEL_30;
    ++v4;
    ++result;
LABEL_6:
    if ( *v4 && (*v4 & 0xC0) == 0x80 )
      goto LABEL_26;
    goto LABEL_30;
  }
  for ( ; (unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer); ++v2 )
    ;
  return v2;
}

// File Line: 50
// RVA: 0x980C70
__int64 __fastcall Scaleform::UTF8Util::GetCharAt(__int64 index, char *putf8str, __int64 length)
{
  __int64 result; // rax
  __int64 v6; // r9
  char v7; // cl
  char v8; // r8
  char v9; // r8
  int v10; // eax
  char v11; // cl
  char v12; // r8
  int v13; // eax
  char v14; // r8
  int v15; // eax
  char v16; // cl
  char v17; // r8
  int v18; // eax
  char v19; // cl
  char v20; // r8
  int v21; // eax
  char v22; // r8
  int v23; // eax
  char v24; // cl
  char v25; // r8
  int v26; // eax
  char v27; // cl
  char v28; // r8
  int v29; // eax
  char v30; // cl
  char v31; // r8
  int v32; // eax
  char v33; // r8
  int v34; // eax
  char v35; // cl
  char v36; // r8
  int v37; // eax
  char v38; // cl
  char v39; // r8
  int v40; // eax
  char v41; // cl
  char v42; // r8
  int v43; // eax
  char v44; // cl
  char v45; // r8
  int v46; // eax
  char *putf8Buffer; // [rsp+38h] [rbp+10h] BYREF

  result = 0i64;
  putf8Buffer = putf8str;
  if ( length == -1 )
  {
    while ( 1 )
    {
      result = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
      --index;
      if ( !(_DWORD)result )
        break;
      if ( index < 0 )
        return result;
    }
    return 0i64;
  }
  else if ( length > 0 )
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = *putf8str++;
      ++v6;
      if ( !v7 )
      {
        result = 0i64;
        goto LABEL_74;
      }
      if ( v7 >= 0 )
      {
        result = (unsigned int)v7;
        goto LABEL_74;
      }
      if ( (v7 & 0xE0) == 0xC0 )
      {
        v8 = *putf8str;
        if ( !*putf8str )
        {
          result = 0i64;
          goto LABEL_74;
        }
        if ( (v8 & 0xC0) == 0x80 )
        {
          ++putf8str;
          ++v6;
          result = v8 & 0x3F | ((unsigned __int8)(v7 & 0x1F) << 6);
          if ( (unsigned int)result < 0x80 )
            result = 65533i64;
          goto LABEL_74;
        }
      }
      else if ( (v7 & 0xF0) == 0xE0 )
      {
        v9 = *putf8str;
        v10 = (v7 & 0xF) << 12;
        if ( !*putf8str )
        {
          result = 0i64;
          goto LABEL_74;
        }
        if ( (v9 & 0xC0) == 0x80 )
        {
          ++putf8str;
          v11 = v9;
          ++v6;
          v12 = *putf8str;
          v13 = ((v11 & 0x3F) << 6) | v10;
          if ( !*putf8str )
          {
            result = 0i64;
            goto LABEL_74;
          }
          if ( (v12 & 0xC0) == 0x80 )
          {
            ++putf8str;
            ++v6;
            result = v12 & 0x3F | (unsigned int)v13;
            if ( (unsigned int)result < 0x800 )
              result = 65533i64;
            goto LABEL_74;
          }
        }
      }
      else if ( (v7 & 0xF8) == 0xF0 )
      {
        v14 = *putf8str;
        v15 = (v7 & 7) << 18;
        if ( !*putf8str )
        {
          result = 0i64;
          goto LABEL_74;
        }
        if ( (v14 & 0xC0) == 0x80 )
        {
          ++putf8str;
          v16 = v14;
          ++v6;
          v17 = *putf8str;
          v18 = ((v16 & 0x3F) << 12) | v15;
          if ( !*putf8str )
          {
            result = 0i64;
            goto LABEL_74;
          }
          if ( (v17 & 0xC0) == 0x80 )
          {
            ++putf8str;
            v19 = v17;
            ++v6;
            v20 = *putf8str;
            v21 = ((v19 & 0x3F) << 6) | v18;
            if ( !*putf8str )
            {
              result = 0i64;
              goto LABEL_74;
            }
            if ( (v20 & 0xC0) == 0x80 )
            {
              ++putf8str;
              ++v6;
              result = v20 & 0x3F | (unsigned int)v21;
              if ( (unsigned int)result < 0x10000 )
                result = 65533i64;
              goto LABEL_74;
            }
          }
        }
      }
      else if ( (v7 & 0xFC) == 0xF8 )
      {
        v22 = *putf8str;
        v23 = (v7 & 3) << 24;
        if ( !*putf8str )
        {
          result = 0i64;
          goto LABEL_74;
        }
        if ( (v22 & 0xC0) == 0x80 )
        {
          ++putf8str;
          v24 = v22;
          ++v6;
          v25 = *putf8str;
          v26 = ((v24 & 0x3F) << 18) | v23;
          if ( !*putf8str )
          {
            result = 0i64;
            goto LABEL_74;
          }
          if ( (v25 & 0xC0) == 0x80 )
          {
            ++putf8str;
            v27 = v25;
            ++v6;
            v28 = *putf8str;
            v29 = ((v27 & 0x3F) << 12) | v26;
            if ( !*putf8str )
            {
              result = 0i64;
              goto LABEL_74;
            }
            if ( (v28 & 0xC0) == 0x80 )
            {
              ++putf8str;
              v30 = v28;
              ++v6;
              v31 = *putf8str;
              v32 = ((v30 & 0x3F) << 6) | v29;
              if ( !*putf8str )
              {
                result = 0i64;
                goto LABEL_74;
              }
              if ( (v31 & 0xC0) == 0x80 )
              {
                ++putf8str;
                ++v6;
                result = v31 & 0x3F | (unsigned int)v32;
                if ( (unsigned int)result < 0x200000 )
                  result = 65533i64;
                goto LABEL_74;
              }
            }
          }
        }
      }
      else if ( (v7 & 0xFE) == 0xFC )
      {
        v33 = *putf8str;
        v34 = (v7 & 1) << 30;
        if ( !*putf8str )
        {
          result = 0i64;
          goto LABEL_74;
        }
        if ( (v33 & 0xC0) == 0x80 )
        {
          ++putf8str;
          v35 = v33;
          ++v6;
          v36 = *putf8str;
          v37 = ((v35 & 0x3F) << 24) | v34;
          if ( !*putf8str )
          {
            result = 0i64;
            goto LABEL_74;
          }
          if ( (v36 & 0xC0) == 0x80 )
          {
            ++putf8str;
            v38 = v36;
            ++v6;
            v39 = *putf8str;
            v40 = ((v38 & 0x3F) << 18) | v37;
            if ( !*putf8str )
            {
              result = 0i64;
              goto LABEL_74;
            }
            if ( (v39 & 0xC0) == 0x80 )
            {
              ++putf8str;
              v41 = v39;
              ++v6;
              v42 = *putf8str;
              v43 = ((v41 & 0x3F) << 12) | v40;
              if ( !*putf8str )
              {
                result = 0i64;
                goto LABEL_74;
              }
              if ( (v42 & 0xC0) == 0x80 )
              {
                ++putf8str;
                v44 = v42;
                ++v6;
                v45 = *putf8str;
                v46 = ((v44 & 0x3F) << 6) | v43;
                if ( !*putf8str )
                {
                  result = 0i64;
                  goto LABEL_74;
                }
                if ( (v45 & 0xC0) == 0x80 )
                {
                  ++putf8str;
                  ++v6;
                  result = v45 & 0x3F | (unsigned int)v46;
                  if ( (unsigned int)result < 0x4000000 )
                    result = 65533i64;
                  goto LABEL_74;
                }
              }
            }
          }
        }
      }
      result = 65533i64;
LABEL_74:
      if ( index )
      {
        --index;
        if ( v6 < length )
          continue;
      }
      return result;
    }
  }
  return result;
}

// File Line: 84
// RVA: 0x980790
__int64 __fastcall Scaleform::UTF8Util::GetByteIndex(__int64 index, char *putf8str, __int64 length)
{
  __int64 v4; // rbx
  char *v5; // r9
  __int64 v6; // rax
  char v7; // dl
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char *putf8Buffer; // [rsp+38h] [rbp+10h] BYREF

  v4 = index;
  v5 = putf8str;
  putf8Buffer = putf8str;
  if ( length != -1 )
  {
    if ( length > 0 )
    {
      v6 = 0i64;
      while ( 1 )
      {
        if ( v4 <= 0 )
          return v5 - putf8str;
        v7 = *v5++;
        ++v6;
        if ( v7 >= 0 )
          goto LABEL_32;
        if ( (v7 & 0xE0) == 0xC0 )
          goto LABEL_29;
        if ( (v7 & 0xF0) == 0xE0 )
          goto LABEL_8;
        if ( (v7 & 0xF8) == 0xF0 )
          goto LABEL_12;
        if ( (v7 & 0xFC) == 0xF8 )
          break;
        if ( (v7 & 0xFE) == 0xFC )
        {
          if ( *v5 )
          {
            if ( (*v5 & 0xC0) == 0x80 )
            {
              v8 = *++v5;
              ++v6;
              if ( v8 )
              {
                if ( (v8 & 0xC0) == 0x80 )
                {
                  v9 = *++v5;
                  ++v6;
                  if ( v9 )
                  {
                    if ( (v9 & 0xC0) == 0x80 )
                    {
                      v10 = *++v5;
                      ++v6;
                      if ( v10 )
                      {
                        if ( (v10 & 0xC0) == 0x80 )
                        {
LABEL_28:
                          ++v5;
                          ++v6;
LABEL_29:
                          if ( *v5 )
                          {
                            if ( (*v5 & 0xC0) == 0x80 )
                            {
                              ++v5;
                              ++v6;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LABEL_32:
        --v4;
        if ( v6 >= length )
          return v5 - putf8str;
      }
      if ( !*v5 || (*v5 & 0xC0) != 0x80 )
        goto LABEL_32;
      ++v5;
      ++v6;
LABEL_12:
      if ( !*v5 || (*v5 & 0xC0) != 0x80 )
        goto LABEL_32;
      ++v5;
      ++v6;
LABEL_8:
      if ( *v5 && (*v5 & 0xC0) == 0x80 )
        goto LABEL_28;
      goto LABEL_32;
    }
    return v5 - putf8str;
  }
  if ( index <= 0 )
    return v5 - putf8str;
  while ( 1 )
  {
    --v4;
    if ( !(unsigned int)Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer) )
      break;
    if ( v4 <= 0 )
      return putf8Buffer - putf8str;
  }
  return putf8Buffer - putf8str;
}

// File Line: 129
// RVA: 0x96C530
__int64 __fastcall Scaleform::UTF8Util::DecodeNextChar_Advance0(char **putf8Buffer)
{
  char v2; // dl
  const char *v3; // rcx
  __int64 result; // rax
  char v5; // r8
  char v6; // dl
  int v7; // r8d
  unsigned int v8; // r8d
  char v9; // r8
  char v10; // dl
  int v11; // r8d
  const char *v12; // rcx
  int v13; // eax
  char v14; // dl
  int v15; // r8d
  unsigned int v16; // r8d
  char v17; // r8
  char v18; // dl
  int v19; // r8d
  const char *v20; // r10
  char v21; // cl
  int v22; // r8d
  const char *v23; // r10
  char v24; // dl
  int v25; // r8d
  unsigned int v26; // r8d
  char v27; // r8
  char v28; // dl
  int v29; // r8d
  const char *v30; // r10
  char v31; // cl
  int v32; // r8d
  const char *v33; // r10
  int v34; // eax
  char v35; // cl
  int v36; // r8d
  const char *v37; // r10
  char v38; // dl
  int v39; // r8d
  unsigned int v40; // r8d
  char v41; // r8
  char v42; // dl
  int v43; // r8d
  const char *v44; // r10
  char v45; // cl
  int v46; // r8d
  const char *v47; // r10
  int v48; // eax
  char v49; // cl
  int v50; // r8d
  const char *v51; // r10
  int v52; // eax
  char v53; // cl
  int v54; // r8d
  const char *v55; // r10
  char v56; // dl
  int v57; // r8d
  unsigned int v58; // r8d

  v2 = **putf8Buffer;
  v3 = *putf8Buffer + 1;
  *putf8Buffer = (char *)v3;
  if ( !v2 )
    return 0i64;
  if ( v2 >= 0 )
    return (unsigned int)v2;
  if ( (v2 & 0xE0) == 0xC0 )
  {
    v5 = v2;
    v6 = *v3;
    v7 = (v5 & 0x1F) << 6;
    if ( *v3 )
    {
      result = 65533i64;
      if ( (v6 & 0xC0) == 0x80 )
      {
        *putf8Buffer = (char *)(v3 + 1);
        v8 = v6 & 0x3F | v7;
        if ( v8 < 0x80 )
          return 65533;
        return v8;
      }
      return result;
    }
    return 0i64;
  }
  if ( (v2 & 0xF0) != 0xE0 )
  {
    if ( (v2 & 0xF8) == 0xF0 )
    {
      v17 = v2;
      v18 = *v3;
      v19 = (v17 & 7) << 18;
      if ( !*v3 )
        return 0i64;
      if ( (v18 & 0xC0) == 0x80 )
      {
        v20 = v3 + 1;
        *putf8Buffer = (char *)(v3 + 1);
        v21 = v3[1];
        v22 = ((v18 & 0x3F) << 12) | v19;
        if ( !v21 )
          return 0i64;
        if ( (v21 & 0xC0) == 0x80 )
        {
          v23 = v20 + 1;
          *putf8Buffer = (char *)v23;
          v24 = *v23;
          v25 = ((v21 & 0x3F) << 6) | v22;
          if ( !*v23 )
            return 0i64;
          result = 65533i64;
          if ( (v24 & 0xC0) == 0x80 )
          {
            *putf8Buffer = (char *)(v23 + 1);
            v26 = v24 & 0x3F | v25;
            if ( v26 < 0x10000 )
              return 65533;
            return v26;
          }
          return result;
        }
      }
    }
    else if ( (v2 & 0xFC) == 0xF8 )
    {
      v27 = v2;
      v28 = *v3;
      v29 = (v27 & 3) << 24;
      if ( !*v3 )
        return 0i64;
      if ( (v28 & 0xC0) == 0x80 )
      {
        v30 = v3 + 1;
        *putf8Buffer = (char *)(v3 + 1);
        v31 = v3[1];
        v32 = ((v28 & 0x3F) << 18) | v29;
        if ( !v31 )
          return 0i64;
        if ( (v31 & 0xC0) == 0x80 )
        {
          v33 = v30 + 1;
          v34 = v31 & 0x3F;
          *putf8Buffer = (char *)v33;
          v35 = *v33;
          v36 = (v34 << 12) | v32;
          if ( !*v33 )
            return 0i64;
          if ( (v35 & 0xC0) == 0x80 )
          {
            v37 = v33 + 1;
            *putf8Buffer = (char *)v37;
            v38 = *v37;
            v39 = ((v35 & 0x3F) << 6) | v36;
            if ( !*v37 )
              return 0i64;
            result = 65533i64;
            if ( (v38 & 0xC0) == 0x80 )
            {
              *putf8Buffer = (char *)(v37 + 1);
              v40 = v38 & 0x3F | v39;
              if ( v40 < 0x200000 )
                return 65533;
              return v40;
            }
            return result;
          }
        }
      }
    }
    else if ( (v2 & 0xFE) == 0xFC )
    {
      v41 = v2;
      v42 = *v3;
      v43 = (v41 & 1) << 30;
      if ( !*v3 )
        return 0i64;
      if ( (v42 & 0xC0) == 0x80 )
      {
        v44 = v3 + 1;
        *putf8Buffer = (char *)(v3 + 1);
        v45 = v3[1];
        v46 = ((v42 & 0x3F) << 24) | v43;
        if ( !v45 )
          return 0i64;
        if ( (v45 & 0xC0) == 0x80 )
        {
          v47 = v44 + 1;
          v48 = v45 & 0x3F;
          *putf8Buffer = (char *)v47;
          v49 = *v47;
          v50 = (v48 << 18) | v46;
          if ( !*v47 )
            return 0i64;
          if ( (v49 & 0xC0) == 0x80 )
          {
            v51 = v47 + 1;
            v52 = v49 & 0x3F;
            *putf8Buffer = (char *)v51;
            v53 = *v51;
            v54 = (v52 << 12) | v50;
            if ( !*v51 )
              return 0i64;
            if ( (v53 & 0xC0) == 0x80 )
            {
              v55 = v51 + 1;
              *putf8Buffer = (char *)v55;
              v56 = *v55;
              v57 = ((v53 & 0x3F) << 6) | v54;
              if ( !*v55 )
                return 0i64;
              result = 65533i64;
              if ( (v56 & 0xC0) == 0x80 )
              {
                *putf8Buffer = (char *)(v55 + 1);
                v58 = v56 & 0x3F | v57;
                if ( v58 < 0x4000000 )
                  return 65533;
                return v58;
              }
              return result;
            }
          }
        }
      }
    }
    return 65533i64;
  }
  v9 = v2;
  v10 = *v3;
  v11 = (v9 & 0xF) << 12;
  if ( !*v3 )
    return 0i64;
  if ( (v10 & 0xC0) != 0x80 )
    return 65533i64;
  v12 = v3 + 1;
  v13 = v10 & 0x3F;
  *putf8Buffer = (char *)v12;
  v14 = *v12;
  v15 = (v13 << 6) | v11;
  if ( !*v12 )
    return 0i64;
  result = 65533i64;
  if ( (v14 & 0xC0) == 0x80 )
  {
    *putf8Buffer = (char *)(v12 + 1);
    v16 = v14 & 0x3F | v15;
    if ( v16 < 0x800 )
      return 65533;
    return v16;
  }
  return result;
}

// File Line: 307
// RVA: 0x96C890
__int64 __fastcall Scaleform::UTF8Util::DecodeString(wchar_t *pbuff, char *putf8str, __int64 bytesLen)
{
  char *v4; // rbx
  wchar_t *v5; // r14
  char v7; // cl
  unsigned int v8; // eax
  char v9; // dl
  bool v10; // cf
  char v11; // dl
  int v12; // eax
  char v13; // cl
  char v14; // dl
  int v15; // eax
  char v16; // dl
  int v17; // eax
  char v18; // cl
  char v19; // dl
  int v20; // eax
  char v21; // cl
  char v22; // dl
  int v23; // eax
  char v24; // dl
  int v25; // eax
  char v26; // cl
  char v27; // dl
  int v28; // eax
  char v29; // cl
  char v30; // dl
  int v31; // eax
  char v32; // cl
  char v33; // dl
  int v34; // eax
  char v35; // dl
  int v36; // eax
  char v37; // cl
  char v38; // dl
  int v39; // eax
  char v40; // cl
  char v41; // dl
  int v42; // eax
  char v43; // cl
  char v44; // dl
  int v45; // eax
  char v46; // cl
  char v47; // dl
  int v48; // eax
  unsigned int v49; // eax
  char *putf8Buffer; // [rsp+40h] [rbp+8h] BYREF

  v4 = putf8str;
  v5 = pbuff;
  if ( bytesLen == -1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v7 = *v4++;
        if ( !v7 )
          goto LABEL_55;
        if ( v7 >= 0 )
        {
          v8 = v7;
          goto LABEL_47;
        }
        if ( (v7 & 0xE0) != 0xC0 )
          break;
        v9 = *v4;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v9 & 0xC0) == 0x80 )
        {
          ++v4;
          v8 = v9 & 0x3F | ((v7 & 0x1F) << 6);
          v10 = v8 < 0x80;
          goto LABEL_9;
        }
LABEL_10:
        *v5++ = -3;
      }
      if ( (v7 & 0xF0) == 0xE0 )
      {
        v11 = *v4;
        v12 = (v7 & 0xF) << 12;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v11 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v13 = v11;
        v14 = *v4;
        v15 = ((v13 & 0x3F) << 6) | v12;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v14 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v8 = v14 & 0x3F | v15;
        v10 = v8 < 0x800;
      }
      else if ( (v7 & 0xF8) == 0xF0 )
      {
        v16 = *v4;
        v17 = (v7 & 7) << 18;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v16 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v18 = v16;
        v19 = *v4;
        v20 = ((v18 & 0x3F) << 12) | v17;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v19 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v21 = v19;
        v22 = *v4;
        v23 = ((v21 & 0x3F) << 6) | v20;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v22 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v8 = v22 & 0x3F | v23;
        v10 = v8 < 0x10000;
      }
      else
      {
        if ( (v7 & 0xFC) != 0xF8 )
        {
          if ( (v7 & 0xFE) == 0xFC )
          {
            v35 = *v4;
            v36 = (v7 & 1) << 30;
            if ( !*v4 )
              goto LABEL_55;
            if ( (v35 & 0xC0) == 0x80 )
            {
              ++v4;
              v37 = v35;
              v38 = *v4;
              v39 = ((v37 & 0x3F) << 24) | v36;
              if ( !*v4 )
                goto LABEL_55;
              if ( (v38 & 0xC0) == 0x80 )
              {
                ++v4;
                v40 = v38;
                v41 = *v4;
                v42 = ((v40 & 0x3F) << 18) | v39;
                if ( !*v4 )
                  goto LABEL_55;
                if ( (v41 & 0xC0) == 0x80 )
                {
                  ++v4;
                  v43 = v41;
                  v44 = *v4;
                  v45 = ((v43 & 0x3F) << 12) | v42;
                  if ( !*v4 )
                    goto LABEL_55;
                  if ( (v44 & 0xC0) == 0x80 )
                  {
                    ++v4;
                    v46 = v44;
                    v47 = *v4;
                    v48 = ((v46 & 0x3F) << 6) | v45;
                    if ( !*v4 )
                      goto LABEL_55;
                    if ( (v47 & 0xC0) == 0x80 )
                    {
                      ++v4;
                      v8 = v47 & 0x3F | v48;
                      if ( v8 >= 0x4000000 )
                        goto LABEL_47;
                    }
                  }
                }
              }
            }
          }
          goto LABEL_10;
        }
        v24 = *v4;
        v25 = (v7 & 3) << 24;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v24 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v26 = v24;
        v27 = *v4;
        v28 = ((v26 & 0x3F) << 18) | v25;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v27 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v29 = v27;
        v30 = *v4;
        v31 = ((v29 & 0x3F) << 12) | v28;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v30 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v32 = v30;
        v33 = *v4;
        v34 = ((v32 & 0x3F) << 6) | v31;
        if ( !*v4 )
          goto LABEL_55;
        if ( (v33 & 0xC0) != 0x80 )
          goto LABEL_10;
        ++v4;
        v8 = v33 & 0x3F | v34;
        v10 = v8 < 0x200000;
      }
LABEL_9:
      if ( v10 )
        goto LABEL_10;
LABEL_47:
      if ( !v8 )
        goto LABEL_55;
      if ( v8 >= 0xFFFF )
        LOWORD(v8) = -3;
      *v5++ = v8;
    }
  }
  putf8Buffer = putf8str;
  if ( bytesLen > 0 )
  {
    do
    {
      v49 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
      if ( v49 >= 0xFFFF )
        LOWORD(v49) = -3;
      *v5++ = v49;
    }
    while ( putf8Buffer - v4 < bytesLen );
  }
LABEL_55:
  *v5 = 0;
  return v5 - pbuff;
}

// File Line: 338
// RVA: 0x970380
void __fastcall Scaleform::UTF8Util::EncodeCharSafe(
        char *pbuffer,
        unsigned __int64 buffLen,
        __int64 *pindex,
        unsigned int ucs_character)
{
  if ( ucs_character <= 0x7F )
  {
    if ( buffLen )
      pbuffer[(*pindex)++] = ucs_character;
    return;
  }
  if ( ucs_character <= 0x7FF )
  {
    if ( buffLen < 2 )
      return;
    pbuffer[*pindex] = (ucs_character >> 6) | 0xC0;
    goto LABEL_22;
  }
  if ( ucs_character <= 0xFFFF )
  {
    if ( buffLen < 3 )
      return;
    pbuffer[*pindex] = (ucs_character >> 12) | 0xE0;
    goto LABEL_21;
  }
  if ( ucs_character <= 0x1FFFFF )
  {
    if ( buffLen < 4 )
      return;
    pbuffer[*pindex] = (ucs_character >> 18) | 0xF0;
    goto LABEL_20;
  }
  if ( ucs_character <= 0x3FFFFFF )
  {
    if ( buffLen < 5 )
      return;
    pbuffer[*pindex] = HIBYTE(ucs_character) | 0xF8;
    goto LABEL_19;
  }
  if ( ucs_character <= 0x7FFFFFFF && buffLen >= 6 )
  {
    pbuffer[(*pindex)++] = (ucs_character >> 30) | 0xFC;
    pbuffer[*pindex] = HIBYTE(ucs_character) & 0x3F | 0x80;
LABEL_19:
    pbuffer[++*pindex] = (ucs_character >> 18) & 0x3F | 0x80;
LABEL_20:
    pbuffer[++*pindex] = (ucs_character >> 12) & 0x3F | 0x80;
LABEL_21:
    pbuffer[++*pindex] = (ucs_character >> 6) & 0x3F | 0x80;
LABEL_22:
    pbuffer[++*pindex] = ucs_character & 0x3F | 0x80;
    ++*pindex;
  }
}

// File Line: 421
// RVA: 0x982D80
__int64 __fastcall Scaleform::UTF8Util::GetEncodeStringSize(const wchar_t *pchar, __int64 length)
{
  __int64 v2; // r9
  const wchar_t *v3; // r10
  int v4; // r8d
  unsigned int v5; // ecx
  int v6; // eax
  wchar_t v8; // ax
  __int64 i; // rdx
  int v10; // eax

  v2 = 0i64;
  v3 = pchar;
  if ( length == -1 )
  {
    v8 = *pchar;
    for ( i = 0i64; v8; v8 = pchar[i] )
    {
      if ( v8 > 0x7Fu )
      {
        if ( v8 > 0x7FFu )
          v10 = 3;
        else
          v10 = 2;
      }
      else
      {
        v10 = 1;
      }
      ++i;
      v2 += v10;
    }
    return v2;
  }
  v4 = 0;
  if ( length <= 0 )
    return v2;
  do
  {
    v5 = *v3;
    if ( v5 > 0x7F )
    {
      if ( v5 > 0x7FF )
        v6 = 3;
      else
        v6 = 2;
    }
    else
    {
      v6 = 1;
    }
    ++v4;
    ++v3;
    v2 += v6;
  }
  while ( v4 < length );
  return v2;
}

// File Line: 439
// RVA: 0x9704C0
void __fastcall Scaleform::UTF8Util::EncodeStringSafe(
        char *pbuff,
        __int64 buffLen,
        const wchar_t *pchar,
        __int64 length)
{
  __int64 v4; // rax
  int i; // esi
  __int64 pindex; // [rsp+48h] [rbp+10h] BYREF

  if ( buffLen )
  {
    v4 = 0i64;
    pindex = 0i64;
    if ( length == -1 )
    {
      if ( buffLen > 0 )
      {
        do
        {
          if ( !*pchar )
            break;
          Scaleform::UTF8Util::EncodeCharSafe(pbuff, buffLen - v4, &pindex, *pchar);
          v4 = pindex;
          ++pchar;
        }
        while ( pindex < buffLen );
      }
    }
    else
    {
      for ( i = 0; i < length; v4 = pindex )
      {
        if ( v4 >= buffLen )
          break;
        Scaleform::UTF8Util::EncodeCharSafe(pbuff, buffLen - v4, &pindex, *pchar);
        ++i;
        ++pchar;
      }
    }
    pbuff[v4] = 0;
  }
}

// File Line: 466
// RVA: 0x96CC30
__int64 __fastcall Scaleform::UTF8Util::DecodeStringSafe(
        wchar_t *pbuff,
        unsigned __int64 buffLen,
        char *putf8str,
        __int64 bytesLen)
{
  char *v5; // rbx
  wchar_t *v6; // r14
  wchar_t *v9; // rbp
  char v10; // cl
  unsigned int v11; // eax
  char v12; // dl
  bool v13; // cf
  char v14; // dl
  int v15; // eax
  char v16; // cl
  char v17; // dl
  int v18; // eax
  char v19; // dl
  int v20; // eax
  char v21; // cl
  char v22; // dl
  int v23; // eax
  char v24; // cl
  char v25; // dl
  int v26; // eax
  char v27; // dl
  int v28; // eax
  char v29; // cl
  char v30; // dl
  int v31; // eax
  char v32; // cl
  char v33; // dl
  int v34; // eax
  char v35; // cl
  char v36; // dl
  int v37; // eax
  char v38; // dl
  int v39; // eax
  char v40; // cl
  char v41; // dl
  int v42; // eax
  char v43; // cl
  char v44; // dl
  int v45; // eax
  char v46; // cl
  char v47; // dl
  int v48; // eax
  char v49; // cl
  char v50; // dl
  int v51; // eax
  unsigned int v52; // eax
  char *putf8Buffer; // [rsp+48h] [rbp+10h] BYREF

  v5 = putf8str;
  v6 = pbuff;
  if ( !buffLen )
    return 0i64;
  v9 = &pbuff[buffLen];
  if ( bytesLen == -1 )
  {
    if ( pbuff < v9 )
    {
      while ( 1 )
      {
        v10 = *v5++;
        if ( !v10 )
          goto LABEL_61;
        if ( v10 >= 0 )
        {
          v11 = v10;
          goto LABEL_52;
        }
        if ( (v10 & 0xE0) == 0xC0 )
          break;
        if ( (v10 & 0xF0) == 0xE0 )
        {
          v14 = *v5;
          v15 = (v10 & 0xF) << 12;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v14 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v16 = v14;
          v17 = *v5;
          v18 = ((v16 & 0x3F) << 6) | v15;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v17 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v11 = v17 & 0x3F | v18;
          v13 = v11 < 0x800;
          goto LABEL_12;
        }
        if ( (v10 & 0xF8) == 0xF0 )
        {
          v19 = *v5;
          v20 = (v10 & 7) << 18;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v19 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v21 = v19;
          v22 = *v5;
          v23 = ((v21 & 0x3F) << 12) | v20;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v22 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v24 = v22;
          v25 = *v5;
          v26 = ((v24 & 0x3F) << 6) | v23;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v25 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v11 = v25 & 0x3F | v26;
          v13 = v11 < 0x10000;
          goto LABEL_12;
        }
        if ( (v10 & 0xFC) == 0xF8 )
        {
          v27 = *v5;
          v28 = (v10 & 3) << 24;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v27 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v29 = v27;
          v30 = *v5;
          v31 = ((v29 & 0x3F) << 18) | v28;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v30 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v32 = v30;
          v33 = *v5;
          v34 = ((v32 & 0x3F) << 12) | v31;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v33 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v35 = v33;
          v36 = *v5;
          v37 = ((v35 & 0x3F) << 6) | v34;
          if ( !*v5 )
            goto LABEL_61;
          if ( (v36 & 0xC0) != 0x80 )
            goto LABEL_13;
          ++v5;
          v11 = v36 & 0x3F | v37;
          v13 = v11 < 0x200000;
          goto LABEL_12;
        }
        if ( (v10 & 0xFE) != 0xFC )
          goto LABEL_13;
        v38 = *v5;
        v39 = (v10 & 1) << 30;
        if ( !*v5 )
          goto LABEL_61;
        if ( (v38 & 0xC0) != 0x80 )
          goto LABEL_13;
        ++v5;
        v40 = v38;
        v41 = *v5;
        v42 = ((v40 & 0x3F) << 24) | v39;
        if ( !*v5 )
          goto LABEL_61;
        if ( (v41 & 0xC0) != 0x80 )
          goto LABEL_13;
        ++v5;
        v43 = v41;
        v44 = *v5;
        v45 = ((v43 & 0x3F) << 18) | v42;
        if ( !*v5 )
          goto LABEL_61;
        if ( (v44 & 0xC0) != 0x80 )
          goto LABEL_13;
        ++v5;
        v46 = v44;
        v47 = *v5;
        v48 = ((v46 & 0x3F) << 12) | v45;
        if ( !*v5 )
          goto LABEL_61;
        if ( (v47 & 0xC0) != 0x80 )
          goto LABEL_13;
        ++v5;
        v49 = v47;
        v50 = *v5;
        v51 = ((v49 & 0x3F) << 6) | v48;
        if ( !*v5 )
          goto LABEL_61;
        if ( (v50 & 0xC0) != 0x80 || (++v5, v11 = v50 & 0x3F | v51, v11 < 0x4000000) )
        {
LABEL_13:
          LOWORD(v11) = -3;
          goto LABEL_14;
        }
LABEL_52:
        if ( !v11 )
          goto LABEL_61;
        if ( v11 >= 0xFFFF )
          LOWORD(v11) = -3;
LABEL_14:
        *v6++ = v11;
        if ( v6 >= v9 )
          goto LABEL_61;
      }
      v12 = *v5;
      if ( !*v5 )
        goto LABEL_61;
      if ( (v12 & 0xC0) != 0x80 )
        goto LABEL_13;
      ++v5;
      v11 = v12 & 0x3F | ((v10 & 0x1F) << 6);
      v13 = v11 < 0x80;
LABEL_12:
      if ( v13 )
        goto LABEL_13;
      goto LABEL_52;
    }
  }
  else
  {
    putf8Buffer = putf8str;
    if ( bytesLen > 0 )
    {
      do
      {
        if ( v6 >= v9 )
          break;
        v52 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
        if ( v52 >= 0xFFFF )
          LOWORD(v52) = -3;
        *v6++ = v52;
      }
      while ( putf8Buffer - v5 < bytesLen );
    }
  }
LABEL_61:
  *v6 = 0;
  return v6 - pbuff;
}

