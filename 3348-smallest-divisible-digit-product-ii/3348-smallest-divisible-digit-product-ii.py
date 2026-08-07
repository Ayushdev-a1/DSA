class Solution:

  def smallestNumber(self, num: str, t: int) -> str:
    # Prime factor counts for digits 0..9
    FACTOR2 = [0, 0, 1, 0, 2, 0, 1, 0, 3, 0]
    FACTOR3 = [0, 0, 0, 1, 0, 0, 1, 0, 0, 2]
    FACTOR5 = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0]
    FACTOR7 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]

    # Step 1: Prime factorize t
    temp = t
    e2 = e3 = e5 = e7 = 0
    while temp % 2 == 0:
      e2 += 1
      temp //= 2
    while temp % 3 == 0:
      e3 += 1
      temp //= 3
    while temp % 5 == 0:
      e5 += 1
      temp //= 5
    while temp % 7 == 0:
      e7 += 1
      temp //= 7

    if temp > 1:
      return "-1"

    # Helper: Minimum digits needed to cover required prime factors
    def min_digits_needed(r2, r3, r5, r7):
      r2, r3, r5, r7 = max(0, r2), max(0, r3), max(0, r5), max(0, r7)

      c9 = r3 // 2
      rem3 = r3 % 2
      c8 = r2 // 3
      rem2 = r2 % 3

      c6 = c4 = c3 = c2 = 0

      if rem2 == 1 and rem3 == 1:
        c6 = 1
      elif rem2 == 2 and rem3 == 1:
        c6 = 1
        c2 = 1
      elif rem2 == 1 and rem3 == 0:
        c2 = 1
      elif rem2 == 2 and rem3 == 0:
        c4 = 1
      elif rem2 == 0 and rem3 == 1:
        c3 = 1

      return c9 + c8 + c6 + c4 + c3 + c2 + r5 + r7

    # Helper: Greedily construct smallest valid suffix
    def build_suffix(rem_len, r2, r3, r5, r7):
      res = []
      for pos in range(rem_len):
        rem_positions = rem_len - 1 - pos
        for d in range(1, 10):
          nr2 = r2 - FACTOR2[d]
          nr3 = r3 - FACTOR3[d]
          nr5 = r5 - FACTOR5[d]
          nr7 = r7 - FACTOR7[d]
          if min_digits_needed(nr2, nr3, nr5, nr7) <= rem_positions:
            res.append(str(d))
            r2, r3, r5, r7 = nr2, nr3, nr5, nr7
            break
      return "".join(res)

    n = len(num)

    # Step 2: Compute prefix factor counts of num
    pref_c2 = [0] * (n + 1)
    pref_c3 = [0] * (n + 1)
    pref_c5 = [0] * (n + 1)
    pref_c7 = [0] * (n + 1)

    first_zero_idx = n
    for idx, ch in enumerate(num):
      if ch == "0":
        first_zero_idx = idx
        break
      d = int(ch)
      pref_c2[idx + 1] = pref_c2[idx] + FACTOR2[d]
      pref_c3[idx + 1] = pref_c3[idx] + FACTOR3[d]
      pref_c5[idx + 1] = pref_c5[idx] + FACTOR5[d]
      pref_c7[idx + 1] = pref_c7[idx] + FACTOR7[d]

    # Step 3: Try to find a valid number of length N
    for i in range(min(n, first_zero_idx), -1, -1):
      if i == n:
        if (
            pref_c2[n] >= e2
            and pref_c3[n] >= e3
            and pref_c5[n] >= e5
            and pref_c7[n] >= e7
        ):
          return num
        continue

      start_d = int(num[i]) + 1
      for d in range(start_d, 10):
        r2 = e2 - pref_c2[i] - FACTOR2[d]
        r3 = e3 - pref_c3[i] - FACTOR3[d]
        r5 = e5 - pref_c5[i] - FACTOR5[d]
        r7 = e7 - pref_c7[i] - FACTOR7[d]

        rem_positions = n - 1 - i
        if min_digits_needed(r2, r3, r5, r7) <= rem_positions:
          prefix = num[:i] + str(d)
          suffix = build_suffix(rem_positions, r2, r3, r5, r7)
          return prefix + suffix

    # Step 4: If no valid length N number exists, construct length > N
    target_len = max(n + 1, min_digits_needed(e2, e3, e5, e7))
    return build_suffix(target_len, e2, e3, e5, e7)