// File Line: 68
// RVA: 0xEC2D48
__int64 __fastcall OSuite::ZHttp::HttpToOsError(int httpError)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  if ( httpError <= 8 )
  {
    if ( httpError != 8 )
    {
      if ( !httpError )
        return 0i64;
      v1 = httpError - 1;
      if ( !v1 )
        return 11i64;
      v2 = v1 - 1;
      if ( v2 )
      {
        v3 = v2 - 1;
        if ( v3 )
        {
          v4 = v3 - 1;
          if ( v4 )
          {
            v5 = v4 - 1;
            if ( v5 )
            {
              v6 = v5 - 1;
              if ( v6 )
              {
                if ( v6 == 1 )
                  return 10i64;
                return 1i64;
              }
              return 9i64;
            }
            return 12i64;
          }
          return 11i64;
        }
        return 5i64;
      }
      return 12i64;
    }
    return 9i64;
  }
  v8 = httpError - 9;
  if ( !v8 )
    return 22i64;
  v9 = v8 - 1;
  if ( !v9 )
    return 5i64;
  v10 = v9 - 1;
  if ( !v10 )
    return 21i64;
  v11 = v10 - 1;
  if ( !v11 )
    return 22i64;
  v12 = v11 - 1;
  if ( !v12 )
    return 4i64;
  v13 = v12 - 1;
  if ( !v13 )
    return 12i64;
  v14 = v13 - 1;
  if ( !v14 )
    return 9i64;
  if ( v14 != 1 )
    return 1i64;
  return 8i64;
}

