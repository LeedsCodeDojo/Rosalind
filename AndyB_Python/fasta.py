"""

"""


def read_fasta(fp):
    """
    Read a FASTA file containing 1 or more sequences of DNA or Peptides.
    Each Sequence has a name and then 1 or more lines of DNA/Peptides

    Returns a generatot
    """
    name, seq = None, []
    for line in fp:
        line = line.rstrip()
        if line.startswith(">"):
            if name: yield (name, ''.join(seq))
            name, seq = line[1:], []
        else:
            seq.append(line)
    if name: yield (name, ''.join(seq))
