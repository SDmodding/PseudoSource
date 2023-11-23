// File Line: 23
// RVA: 0xA2AE40
__int64 __fastcall UFG::UILanguages::getLanguage(const char *language)
{
  unsigned int v1; // ebx
  __int64 result; // rax

  v1 = -1;
  result = UFG::qStringCompareInsensitive(language, "Debug-Blank", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Debug-Label", -1) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Debug-MaxString", -1) )
      {
        if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Debug-NumericID", -1) )
        {
          if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Cantonese", -1) )
          {
            if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Danish", -1) )
            {
              if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Dutch", -1) )
              {
                if ( (unsigned int)UFG::qStringCompareInsensitive(language, "English", -1) )
                {
                  if ( (unsigned int)UFG::qStringCompareInsensitive(language, "English-UK", -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Finnish", -1) )
                    {
                      if ( (unsigned int)UFG::qStringCompareInsensitive(language, "French", -1) )
                      {
                        if ( (unsigned int)UFG::qStringCompareInsensitive(language, "French-CA", -1) )
                        {
                          if ( (unsigned int)UFG::qStringCompareInsensitive(language, "German", -1) )
                          {
                            if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Italian", -1) )
                            {
                              if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Japanese", -1) )
                              {
                                if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Korean", -1) )
                                {
                                  if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Norwegian", -1) )
                                  {
                                    if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Polish", -1) )
                                    {
                                      if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Portuguese", -1) )
                                      {
                                        if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Portuguese-BR", -1) )
                                        {
                                          if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Russian", -1) )
                                          {
                                            if ( (unsigned int)UFG::qStringCompareInsensitive(language, "Spanish", -1) )
                                            {
                                              if ( (unsigned int)UFG::qStringCompareInsensitive(
                                                                   language,
                                                                   "Spanish-US",
                                                                   -1) )
                                              {
                                                if ( !(unsigned int)UFG::qStringCompareInsensitive(
                                                                      language,
                                                                      "Swedish",
                                                                      -1) )
                                                  return 23;
                                                return v1;
                                              }
                                              else
                                              {
                                                return 22i64;
                                              }
                                            }
                                            else
                                            {
                                              return 21i64;
                                            }
                                          }
                                          else
                                          {
                                            return 20i64;
                                          }
                                        }
                                        else
                                        {
                                          return 19i64;
                                        }
                                      }
                                      else
                                      {
                                        return 18i64;
                                      }
                                    }
                                    else
                                    {
                                      return 17i64;
                                    }
                                  }
                                  else
                                  {
                                    return 16i64;
                                  }
                                }
                                else
                                {
                                  return 15i64;
                                }
                              }
                              else
                              {
                                return 14i64;
                              }
                            }
                            else
                            {
                              return 13i64;
                            }
                          }
                          else
                          {
                            return 12i64;
                          }
                        }
                        else
                        {
                          return 11i64;
                        }
                      }
                      else
                      {
                        return 10i64;
                      }
                    }
                    else
                    {
                      return 9i64;
                    }
                  }
                  else
                  {
                    return 8i64;
                  }
                }
                else
                {
                  return 7i64;
                }
              }
              else
              {
                return 6i64;
              }
            }
            else
            {
              return 5i64;
            }
          }
          else
          {
            return 4i64;
          }
        }
        else
        {
          return 3i64;
        }
      }
      else
      {
        return 2i64;
      }
    }
    else
    {
      return 1i64;
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
    case eLang_DebugBlank:
      result = "Debug-Blank";
      break;
    case eLang_DebugLabel:
      result = "Debug-Label";
      break;
    case eLang_DebugMaxString:
      result = "Debug-MaxString";
      break;
    case eLang_DebugNumericID:
      result = "Debug-NumericID";
      break;
    case eLang_Cantonese:
      result = "Cantonese";
      break;
    case eLang_Danish:
      result = "Danish";
      break;
    case eLang_Dutch:
      result = "Dutch";
      break;
    case eLang_English:
      result = "English";
      break;
    case eLang_English_UK:
      result = "English-UK";
      break;
    case eLang_Finnish:
      result = "Finnish";
      break;
    case eLang_French:
      result = "French";
      break;
    case eLang_French_CA:
      result = "French-CA";
      break;
    case eLang_German:
      result = "German";
      break;
    case eLang_Italian:
      result = "Italian";
      break;
    case eLang_Japanese:
      result = "Japanese";
      break;
    case eLang_Korean:
      result = "Korean";
      break;
    case eLang_Norwegian:
      result = "Norwegian";
      break;
    case eLang_Polish:
      result = "Polish";
      break;
    case eLang_Portuguese:
      result = "Portuguese";
      break;
    case eLang_Portuguese_BR:
      result = "Portuguese-BR";
      break;
    case eLang_Russian:
      result = "Russian";
      break;
    case eLang_Spanish:
      result = "Spanish";
      break;
    case eLang_Spanish_US:
      result = "Spanish-US";
      break;
    case eLang_Swedish:
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
    case eLang_DebugBlank:
      result = "DBG_BLNK";
      break;
    case eLang_DebugLabel:
      result = "DBG_LBL";
      break;
    case eLang_DebugMaxString:
      result = "DBG_MAX";
      break;
    case eLang_DebugNumericID:
      result = "DBG_ID";
      break;
    case eLang_Cantonese:
      result = "CN";
      break;
    case eLang_Danish:
      result = "DA";
      break;
    case eLang_Dutch:
      result = "DU";
      break;
    case eLang_English:
      result = "EN";
      break;
    case eLang_English_UK:
      result = "UK";
      break;
    case eLang_Finnish:
      result = "FI";
      break;
    case eLang_French:
      result = "FR";
      break;
    case eLang_French_CA:
      result = "FC";
      break;
    case eLang_German:
      result = "DE";
      break;
    case eLang_Italian:
      result = "IT";
      break;
    case eLang_Japanese:
      result = "JP";
      break;
    case eLang_Korean:
      result = "KO";
      break;
    case eLang_Norwegian:
      result = "NO";
      break;
    case eLang_Polish:
      result = "PO";
      break;
    case eLang_Portuguese:
      result = "PR";
      break;
    case eLang_Portuguese_BR:
      result = "PB";
      break;
    case eLang_Russian:
      result = "RU";
      break;
    case eLang_Spanish:
      result = "SP";
      break;
    case eLang_Spanish_US:
      result = "SU";
      break;
    case eLang_Swedish:
      result = "SW";
      break;
    default:
      result = "INVALID";
      break;
  }
  return result;
}

