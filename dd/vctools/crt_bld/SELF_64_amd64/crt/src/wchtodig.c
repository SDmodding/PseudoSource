// File Line: 32
// RVA: 0x12DD5B8
__int64 __fastcall wchartodigit(wchar_t ch)
{
  int v1; // edx
  wchar_t v3; // ax

  v1 = 48;
  if ( ch < 0x30u )
    return 0xFFFFFFFFi64;
  if ( ch < 0x3Au )
    return (unsigned int)ch - v1;
  v1 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = -230;
LABEL_38:
    if ( ch < v3 )
      return (unsigned int)ch - v1;
    return 0xFFFFFFFFi64;
  }
  v1 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return (unsigned int)ch - v1;
    v1 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return (unsigned int)ch - v1;
      v1 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return (unsigned int)ch - v1;
        v1 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return (unsigned int)ch - v1;
          v1 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return (unsigned int)ch - v1;
            v1 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return (unsigned int)ch - v1;
              v1 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return (unsigned int)ch - v1;
                v1 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return (unsigned int)ch - v1;
                  v1 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return (unsigned int)ch - v1;
                    v1 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return (unsigned int)ch - v1;
                      v1 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return (unsigned int)ch - v1;
                        v1 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return (unsigned int)ch - v1;
                          v1 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return (unsigned int)ch - v1;
                            v1 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return (unsigned int)ch - v1;
                              v1 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return (unsigned int)ch - v1;
                                v1 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = 6170;
                                  goto LABEL_38;
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
          }
        }
      }
    }
  }
  return 0xFFFFFFFFi64;
}

