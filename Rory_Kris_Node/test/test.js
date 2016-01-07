import {expect} from 'chai'
import * as lib from '../index'
import fs from 'fs'

describe('Counting DNA Nucleotides', () => {
    it('should return four integers (separated by spaces) counting the respective number of times that the symbols \'A\', \'C\', \'G\', and \'T\' occur.', (done) => {
        fs.readFile('txt/1.txt', 'utf-8', (err, data) => {
            if (err) throw (err)
            expect(lib.countDNANucleotides(data)).to.be.equal('20 12 17 21')
            done()
        })
    })
})

describe('Transcribing DNA into RNA', () => {
    it('should return a transcribed RNA string.', (done) => {
        fs.readFile('txt/2.txt', 'utf-8', (err, data) => {
            if (err) throw (err)
            expect(lib.transcribingDNAtoRNA(data)).to.be.equal('GAUGGAACUUGACUACGUAAAUU')
            done()
        })
    })
})

describe('Complementing a Strand of DNA', () => {
    it('should return the reverse complement of a string.', (done) => {
        fs.readFile('txt/3.txt', 'utf-8', (err, data) => {
            if (err) throw (err)
            expect(lib.complementOfStrand(data)).to.be.equal('ACCGGGTTTT')
            done()
        })
    })
})

describe('Rabbits and Recurrence Relations', () => {
    it('should return the total number of rabbit pairs that will be present after a certain number of months.', (done) => {
        fs.readFile('txt/4.txt', 'utf-8', (err, data) => {
            if (err) throw (err)
            expect(lib.rabbitsAndRecurrence(data)).to.be.equal(19)
            done()
        })
    })
})

describe('Computing GC Content', () => {
    it('should return the ID of the string having the highest GC-content, followed by the GC-content of that string.', (done) => {
        fs.readFile('txt/5.txt', 'utf-8', (err, data) => {
            if (err) throw err
            expect(lib.computeGCContent(data)).to.be.equal('Rosalind_0808\n60.919540')
            done()
        })
    })
})

describe('Counting Point Mutations', () => {
    it('should return the Hamming distance of two strings.', (done) => {
        fs.readFile('txt/6.txt', 'utf-8', (err, data) => {
            if (err) throw (err)
            expect(lib.countingPointMutations(data)).to.be.equal(7)
            done()
        })
    })
})
