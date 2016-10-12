#include "../module.h"

class Sink : public Module {
public:
	virtual void ProcessBatch(struct pkt_batch *batch);

	static const gate_idx_t kNumIGates = 1;
	static const gate_idx_t kNumOGates = 0;
};

void Sink::ProcessBatch(struct pkt_batch *batch) {
	snb_free_bulk(batch->pkts, batch->cnt);
}

ModuleClassRegister<Sink> sink("Sink", "sink", "discards all packets");