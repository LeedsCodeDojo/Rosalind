export function countDNANucleotides(str) {
    const arr = str.split('')

    const arrCount = [0, 0, 0, 0]

    arr.forEach(e => {
        if (e == 'A') arrCount[0]++
        if (e == 'C') arrCount[1]++
        if (e == 'G') arrCount[2]++
        if (e == 'T') arrCount[3]++
    })
    return arrCount.join(' ')
}

export function transcribingDNAtoRNA(str) {
    return str.replace(/T/g, 'U')
}

export function complementOfStrand(str) {
    const arr = str.split('')

    let result = ''

    arr.forEach(e => {
        if (e == 'A') result += 'T'
        if (e == 'C') result += 'G'
        if (e == 'G') result += 'C'
        if (e == 'T') result += 'A'
    })

    return result.split('').reverse().join('')
}

export function rabbitsAndRecurrence(str) {
    const arr = str.split(' ')
    const [months, pairs] = arr

    let childPairs = 1
    let adultPairs = 0
    let existingAdultPairs = 0

    for (var i = 2; i <= months; i++) {
        adultPairs = childPairs
        childPairs = pairs * existingAdultPairs
        existingAdultPairs += adultPairs
    }

    return existingAdultPairs + childPairs
}

export function computeGCContent(str) {
    let arr = str.split('>')

    arr.shift()

    let winningStr = ''
    let winningMax = 0

    for (let i = 0; i < arr.length; i++) {
        let strToTest = arr[i].replace(/\n/g, '')
        strToTest = strToTest.substr(13)
        const arrToTest = strToTest.split('')

        let count = 0
        arrToTest.forEach(e => {
            if (e == 'C' || e == 'G') count++
        })
        const perc = ((count / strToTest.length) * 100).toFixed(6)
        if (perc > winningMax) {
            winningMax = perc
            winningStr = arr[i].substr(0, 13)
        }
    }

    return winningStr + '\n' + winningMax
}

export function countingPointMutations(str) {
    const arr = str.split('\n')
    const [str1, str2] = arr
    const arr1 = str1.split('')
    const arr2 = str2.split('')
    let counter = 0

    arr1.forEach((e, i) => {
        if (e !== arr2[i]) counter++
    })

    return counter
}
