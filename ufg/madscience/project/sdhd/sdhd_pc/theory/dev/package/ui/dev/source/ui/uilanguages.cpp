// File Line: 23
// RVA: 0xA2AE40
signed __int64 __fastcall UFG::UILanguages::getLanguage(const char *language)
{
  unsigned int v1; // ebx
  const char *v2; // rdi
  signed __int64 result; // rax

  v1 = -1;
  v2 = language;
  result = UFG::qStringCompareInsensitive(language, "Debug-Blank", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Debug-Label", -1) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Debug-MaxString", -1) )
      {
        if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Debug-NumericID", -1) )
        {
          if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Cantonese", -1) )
          {
            if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Danish", -1) )
            {
              if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Dutch", -1) )
              {
                if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "English", -1) )
                {
                  if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "English-UK", -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Finnish", -1) )
                    {
                      if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "French", -1) )
                      {
                        if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "French-CA", -1) )
                        {
                          if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "German", -1) )
                          {
                            if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Italian", -1) )
                            {
                              if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Japanese", -1) )
                              {
                                if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Korean", -1) )
                                {
                                  if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Norwegian", -1) )
                                  {
                                    if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Polish", -1) )
                                    {
                                      if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Portuguese", -1) )
                                      {
                                        if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Portuguese-BR", -1) )
                                        {
                                          if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Russian", -1) )
                                          {
                                            if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Spanish", -1) )
                                            {
                                              if ( (unsigned int)UFG::qStringCompareInsensitive(v2, "Spanish-US", -1) )
                                              {
                                                if ( !(unsigned int)UFG::qStringCompareInsensitive(v2, "Swedish", -1) )
                                                  v1 = 23;
                                                result = v1;
                                              }
                                              else
                                              {
                                                result = 22i64;
                                              }
                                            }
                                            else
                                            {
                                              result = 21i64;
                                            }
                                          }
                                          else
                                          {
                                            result = 20i64;
                                          }
                                        }
                                        else
                                        {
                                          result = 19i64;
                                        }
                                      }
                                      else
                                      {
                                        result = 18i64;
                                      }
                                    }
                                    else
                                    {
                                      result = 17i64;
                                    }
                                  }
                                  else
                                  {
                                    result = 16i64;
                                  }
                                }
                                else
                                {
                                  result = 15i64;
                                }
                              }
                              else
                              {
                                result = 14i64;
                              }
                            }
                            else
                            {
                              result = 13i64;
                            }
                          }
                          else
                          {
                            result = 12i64;
                          }
                        }
                        else
                        {
                          result = 11i64;
                        }
                      }
                      else
                      {
                        result = 10i64;
                      }
                    }
                    else
                    {
                      result = 9i64;
                    }
                  }
                  else
                  {
                    result = 8i64;
                  }
                }
                else
                {
                  result = 7i64;
                }
              }
              else
              {
                result = 6i64;
              }
            }
            else
            {
              result = 5i64;
            }
          }
          else
          {
            result = 4i64;
          }
        }
        else
        {
          result = 3i64;
        }
      }
      else
      {
        result = 2i64;
      }
    }
    else
    {
      result = 1i64;
    }
  }
  return result;
}

// File Line: 85
// RVA: 0xA2B200
const char *__fastcall UFG::UILanguages::getLanguageString(UFG::UILanguages::eLanguage language)
{
  const char *result; // rax

  switch ( language )
  {
    case 0u:
      result = "Debug-Blank";
      break;
    case 1u:
      result = "Debug-Label";
      break;
    case 2u:
      result = "Debug-MaxString";
      break;
    case 3u:
      result = "Debug-NumericID";
      break;
    case 4u:
      result = "Cantonese";
      break;
    case 5u:
      result = "Danish";
      break;
    case 6u:
      result = "Dutch";
      break;
    case 7u:
      result = "English";
      break;
    case 8u:
      result = "English-UK";
      break;
    case 9u:
      result = "Finnish";
      break;
    case 0xAu:
      result = "French";
      break;
    case 0xBu:
      result = "French-CA";
      break;
    case 0xCu:
      result = "German";
      break;
    case 0xDu:
      result = "Italian";
      break;
    case 0xEu:
      result = "Japanese";
      break;
    case 0xFu:
      result = "Korean";
      break;
    case 0x10u:
      result = "Norwegian";
      break;
    case 0x11u:
      result = "Polish";
      break;
    case 0x12u:
      result = "Portuguese";
      break;
    case 0x13u:
      result = "Portuguese-BR";
      break;
    case 0x14u:
      result = "Russian";
      break;
    case 0x15u:
      result = "Spanish";
      break;
    case 0x16u:
      result = "Spanish-US";
      break;
    case 0x17u:
      result = "Swedish";
      break;
    default:
      result = "Invalid";
      break;
  }
  return result;
}

// File Line: 150
// RVA: 0xA2B370
const char *__fastcall UFG::UILanguages::getLanguageStringShort(UFG::UILanguages::eLanguage language)
{
  const char *result; // rax

  switch ( language )
  {
    case 0u:
      result = "DBG_BLNK";
      break;
    case 1u:
      result = "DBG_LBL";
      break;
    case 2u:
      result = "DBG_MAX";
      break;
    case 3u:
      result = "DBG_ID";
      break;
    case 4u:
      result = "CN";
      break;
    case 5u:
      result = "DA";
      break;
    case 6u:
      result = "DU";
      break;
    case 7u:
      result = "EN";
      break;
    case 8u:
      result = "UK";
      break;
    case 9u:
      result = "FI";
      break;
    case 0xAu:
      result = "FR";
      break;
    case 0xBu:
      result = "FC";
      break;
    case 0xCu:
      result = "DE";
      break;
    case 0xDu:
      result = "IT";
      break;
    case 0xEu:
      result = "JP";
      break;
    case 0xFu:
      result = "KO";
      break;
    case 0x10u:
      result = "NO";
      break;
    case 0x11u:
      result = "PO";
      break;
    case 0x12u:
      result = "PR";
      break;
    case 0x13u:
      result = "PB";
      break;
    case 0x14u:
      result = "RU";
      break;
    case 0x15u:
      result = "SP";
      break;
    case 0x16u:
      result = "SU";
      break;
    case 0x17u:
      result = "SW";
      break;
    default:
      result = "INVALID";
      break;
  }
  return result;
}

