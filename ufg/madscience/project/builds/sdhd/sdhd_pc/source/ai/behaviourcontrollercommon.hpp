// File Line: 152
// RVA: 0x383E50
const char *__fastcall UFG::InvokeBehaviourResult::ResultEnumToString(int r)
{
  const char *result; // rax

  switch ( r + 5 )
  {
    case 0:
      result = "FAIL_DUPLICATE";
      break;
    case 1:
      result = "FAIL_PRIORITY";
      break;
    case 2:
      result = "FAIL_NOTFOUND";
      break;
    case 3:
      result = "FAIL_WAIT";
      break;
    case 4:
      result = "FAIL_SUSPEND";
      break;
    case 5:
      result = "FAIL";
      break;
    case 6:
      result = "SUCCESS";
      break;
    case 7:
      result = "SUCCESS_WAITING";
      break;
    case 8:
      result = "SUCCESS_SUSPEND";
      break;
    case 9:
      result = "SUCCESS_KILLED";
      break;
    default:
      result = "SUCCESS OTHER";
      if ( r <= 0 )
        result = "FAIL OTHER";
      break;
  }
  return result;
}

