class Sample:
    def __init__(self,label,score):
        self.label=label
        self.score=score

def PR(samples,positive_class):
    samples.sort(key=lambda x:x.score,reverse=True)
    P = [1]
    R = [0]
    positive_num = 0
    for i in range(0,len(samples)):
        if samples[i].label == positive_class:
            positive_num = positive_num + 1
    TP = 0
    for i in range(0,len(samples)):
        if samples[i].label == positive_class:
            TP = TP + 1
        P.append(TP/(i+1))
        R.append(TP/positive_num)
    AUC = []
    AP = []
    for i in range(1,len(P)):
        AUC.append((R[i]-R[i-1])*(P[i]+P[i-1])/2)
        AP.append((R[i]-R[i-1])*P[i])
    a = 0
    for i in range(0,len(AUC)):
        a = a + AUC[i]
        print(AUC[i])
    print('a:' + str(a))
def main():
    samples = []
    samples.append(Sample(1,1.0))
    samples.append(Sample(2,0.9))
    samples.append(Sample(1,0.8))
    samples.append(Sample(1,0.7))
    samples.append(Sample(2,0.6))
    samples.append(Sample(1,0.5))
    samples.append(Sample(2,0.4))
    samples.append(Sample(2,0.3))
    samples.append(Sample(2,0.2))
    samples.append(Sample(1,0.1))
    PR(samples,1)

if __name__ == '__main__':
    main()