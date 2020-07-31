function getZipLength(str, chunkSize) {
  const result = [];
  let index = 0;

  for (let i = 0; i < str.length; i += chunkSize) {
    if (i === 0) {
      result.push({
        char: str.slice(0, chunkSize),
        count: 1,
      });
      continue;
    }

    const char = str.slice(i, i + chunkSize);

    if (char === result[index].char) {
      result[index].count++;
    } else {
      result.push({
        char,
        count: 1,
      });
      index++;
    }
  }

  const resultStr = result.reduce((s, item) => {
    if (item.count > 1) {
      return s + item.count + item.char;
    }

    return s + item.char;
  }, '');

  return resultStr.length;
}

function solution(s) {
  const strLength = s.length;
  let minLength = strLength;

  for (let chunkSize = 1; chunkSize <= strLength; chunkSize++) {
    const length = getZipLength(s, chunkSize);

    if (length < minLength) {
      minLength = length;
    }
  }

  return minLength;
}
